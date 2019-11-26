#include<stdio.h>
#include<stdlib.h>
struct Node 
{ 
    int data; 
    struct Node* link; 
}; 
  
struct Queue 
{ 
    struct Node *front
    struct Node *rear; 
};
void enQueue(struct Queue *q, int value) 
{ 
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = value; 
    if (q->front == NULL) 
        q->front = temp; 
    else
        q->rear->link = temp;  
    q->rear = temp; 
    q->rear->link = q->front; 
}
void deQueue(struct Queue *q) 
{
    if (q->front == NULL) 
    { 
        printf ("Queue is empty"); 
        return INT_MIN; 
    }
    if (q->front == q->rear) 
    { 
       printf("\nDeleted value = %d",q->front->data); 
        free(q->front); 
        q->front = NULL; 
        q->rear = NULL; 
    } 
    else
    { 
        struct Node *temp = q->front; 
        printf("\nDeleted value = %d",temp->data); 
        q->front = q->front->link; 
        q->rear->link= q->front; 
        free(temp); 
    } 
} 
  
// Function displaying the elements of Circular Queue 
void displayQueue(struct Queue* q) 
{ 
    struct Node *temp = q->front; 
    printf("\nElements in Circular Queue are: "); 
    while (temp->link != q->front) 
    { 
        printf("%d ", temp->data); 
        temp = temp->link; 
    } 
    printf("%d", temp->data); 
} 
void main()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Node));; 
    q->front = q->rear = NULL;
    enQueue(q, 14); 
    enQueue(q, 22); 
    enQueue(q, 6);
    displayQueue(q);
    deQueue(q);
    deQueue(q);
    displayQueue(q);
}
