#include<stdio.h>
#include<stdlib.h>
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
struct Node* New_Node(int data) 
{ 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    new_node->data = data; 
    new_node->next = NULL; 
    return new_node; 
}
void push(struct Node** root, int data) 
{ 
    struct Node* new_node = New_Node(data); 
    new_node->next = *root; 
    *root = new_node; 
    printf("%d pushed to stack\n", data); 
} 
int pop(struct Node** root) 
{ 
    if(root == NULL)
        printf("Stack is empty\n");
    struct Node* temp = *root; 
    *root = (*root)->next; 
    int del = temp->data; 
    free(temp); 
    return del; 
}
void main()
{
    struct Node* root = NULL; 
    push(&root, 10); 
    push(&root, 20); 
    push(&root, 30);  
    printf("%d popped from stack\n", pop(&root));
}