/*
Discuss how stacks can be used for checking balancing of symbols.
Solution: Stacks can be used to check whether the given expression has balanced symbols. This
algorithm is very useful in compilers. Each time the parser reads one character at a time. If the
character is an opening delimiter such as (, {, or [- then it is written to the stack. When a closing
delimiter is encountered like ), }, or ]-the stack is popped.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10
char stack[MAX_SIZE];/*size of stack is MAZ_SIZE which is 10*/
int top = -1;/*top of the stack*/
int match(char a,char b);/*function to if check char b is the closing brackect of char a*/
/*function to push element in stack*/
int push(char n){
    if(is_full()){
        return;
    }
    stack[++top] = n;
}
/*function to check if stack is full*/
int is_full(){
    if(top == (MAX_SIZE-1)){
        return 1;
    }else{
        return 0;
    }
}
/*function to check if stack is empty*/
int is_empty(){
    if(top == -1){
        return 1;
    }else{
        return 0;
    }
}
/*function that return top element from the stack and remove top element from the stack*/
char pop(){
    char exp;
    if(is_empty()){
        return ;
    }
    exp = stack[top];
    top--;
    return exp;
}
/*function that returns top element from the stack*/
char rtop(){
    if(is_empty()){
        return;
    }
    return stack[top];
}
/*function to check if the given expression is balanced*/
int check_param(char arr[]){
    int len = strlen(arr);
    for(int i=0;i<len;i++){
        /*if there is any opening bracket like (,{,[ push it to the stack*/
        if(arr[i] == '('){
            push(arr[i]);
        }
        else if(arr[i] == '{'){
            push(arr[i]);
        }
        else if(arr[i] == '['){
            push(arr[i]);
        }
        /*if the above statement didn't matched that means there is closing bracket*/
        else{
            /*if there is closing bracket but the stack is empty that means
              the first character in the expression is closing bracket, which
              makes the whole expression imbalanced
            */
            if(is_empty()){
                return 0;
            }
            /*if the match function return true just pop() and continue interating the expression */
            if(match(rtop(),arr[i])){
                pop();
            }else{
                return 0;
            }
        }
    }
    if(is_empty()){
        return 1;
    }
}
/*function to if check char b is the closing brackect of char a*/
int match(char a,char b){
    if(a == '(' && b == ')'){
        return 1;
    }
    else if(a == '{' && b == '}'){
        return 1;
    }
    else if(a == '[' && b == ']'){
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    char arr[] = "(({[]})[])";/*test case*/
    if(check_param(arr)){
        printf("balanced");
    }else{
        printf("imbalanced");
    }
    return 0;
}

