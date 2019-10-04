/*postfix evaluation using stack*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 30
int stack[MAX_SIZE];/*size of stack is MAZ_SIZE which is 10*/
int top = -1;/*top of the stack*/
int push(int n){
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
int pop(){
    int exp;
    if(is_empty()){
        return NULL;
    }
    exp = stack[top];
    top--;
    return exp;
}
/*function that returns top element from the stack*/
int rtop(){
    if(is_empty()){
        return;
    }
    return stack[top];
}
/*function to evaluate postfix using stack*/
int postfix_evaluate(char arr[]){
    int len = strlen(arr);/*length of the char arr[] for iteration*/
    int a,b;/*variable to store poped values*/
    for(int i=0;i<len;i++){
        /*if the element is digit push the element into the stack*/
        if(isdigit(arr[i])){
            push(arr[i]-'0');
        }
        /*if the element is an operator perform the task written below*/
        else{
            a = pop();/*store the top element of the stack*/
            b = pop();/*store the new top element of the stack*/
            /*if(a == NULL || b == NULL){
                printf("Sting is not postfix.");
                return;
            }*/
            /*switch statement to perform task for each operator*/
            switch(arr[i]){
                /*switch case for sum*/
                case '+':push(b+a);
                break;
                /*switch case for subtraction*/
                case '-':push(b-a);
                break;
                /*switch case for multiplication*/
                case '*':push(b*a);
                break;
                /*switch case for division*/
                case '/':push(b/a);
                break;
            }
        }
    }
    return pop();/*after the end of loop,remaining element of the stack is the result so return
    to the called function*/
}
int main()
{
    char arr[] = "4572+-*";/*test case*/
    printf("result = %d",postfix_evaluate(arr));
    return 0;
}

