#include <stdio.h>
#include <stdlib.h>
/*structure of node*/
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* head;
struct Node* newNode(int data);
struct Node* insert(struct Node* head,int data);
void inOrder(struct Node* head);
int main()
{
    head = insert(NULL,8);
    insert(head,7);
    insert(head,5);
    insert(head,6);
    insert(head,2);
    insert(head,12);
    insert(head,9);
    insert(head,15);
    insert(head,10);
    printf("Inorder traversal:- ");
    inOrder(head);
    return 0;
}
/*function to create new node*/
struct Node* newNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
/*function to insert data in binary search tree*/
struct Node* insert(struct Node* head,int data){
    struct Node* p;
    struct Node* q;
    struct Node* temp;
    p = newNode(data);
    if(head == NULL){
        head = p;
        return head;
    }else{
        q = head;
        temp = NULL;
        while(q != NULL){
            temp = q;
            if(q->data > p->data){
                q = q->left;
            }else if(q->data < p->data){
                q = q->right;
            }
            else{
                return;
            }
        }

        if(temp->data > p->data){
            temp->left = p;
        }else{
            temp->right = p;
        }
    }
    return p;
}
/*
function to traverse binary search tree(inorder traversal)
Inorder (Left, Root, Right)
Algorithm Inorder(tree)
   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Visit the root.
   3. Traverse the right subtree, i.e., call Inorder(right-subtree)
*/
void inOrder(struct Node* head){
    if(head == NULL){
        return;
    }
    inOrder(head->left);
    printf("%d,",head->data);
    inOrder(head->right);
}
