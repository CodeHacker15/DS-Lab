#include <stdio.h> 
#include <stdlib.h>
struct Node
	{
		int info;
		struct Node *next;
		struct Node *prev;
	};
void InsertBegDLL(struct Node **h,int val)
{
	struct Node* temp = *h;
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node -> info = val;
	new_node -> next = *h;
	new_node -> prev = NULL;
	if (temp != NULL)
	{		
		temp -> prev = new_node;
	}
	*h = new_node;
}
void InsertEndDLL(struct Node **h,int val)
{
	struct Node* last = *h;
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node -> info = val;
	new_node -> next = NULL;
	if(*h == NULL) 
    {
		new_node -> prev = NULL;
		*h = new_node;
		return;
	}
	while(last -> next != NULL)
	{
		last = last -> next;
	}
	last -> next = new_node;
	new_node -> prev = last;
	return;
}
void InsertPosDLL(struct Node **prev_node,int val)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	if(prev_node == NULL)
	{
		printf("Previous Node cannot be NULL");
		return;
	}
	new_node -> info = val;
	new_node -> next = prev_node -> next;
	prev_node -> next = new_node;
	new_node -> prev = prev_node;
	if(new_node -> next != NULL)
		new_node -> next -> prev = new_node;
}
int DeleteBegDLL(struct Node **h)
{
	int val;
	if(*h == NULL)
	{
		printf("Linked List is empty");
		return;
	}
	struct Node* temp = *h;
	val = temp -> info;
	*h = temp -> next;
	temp -> next -> prev = NULL;
	free(temp);
	return val;
}
int DeleteLastDLL(struct Node **h)
{
	int val;
	if(*h == NULL)
	{
		printf("Linked List is empty");
		return;
	}
	struct Node* temp = *h;
	while(temp->next != NULL)
	{
		temp = temp -> next;
	}
	temp -> prev -> next = NULL;
	free(temp);
}
void PrintListDLL(struct Node *node) 
{ 
	struct Node* last;
	printf("\n");
	printf("Printing in forward direction! \n");
	while(node != NULL) 
	{ 
		printf("| %d |", node -> info);  
		last = node;
		node = node -> next;
	}
	printf("\n");
	printf("Printing in reverse direction! \n");
	while(last!=NULL)
	{
	  printf("| %d |", last -> info);
	  last = last -> prev;
	}
	printf("\n");
}
void main()
{	
	int ch,val,delval,pos;
	struct Node *head=NULL;
	loop:
	printf("\n=====Welcome to LinkList Insertion===== \n");
	printf("1.Insert at beginning \n");
	printf("2.Insert at last \n");
	printf("3.Insert at specific position \n");
	printf("4.Delete at beginning \n");
	printf("5.Delete at last \n");
	printf("6.Delete at specific position \n");
	printf("7.Print List \n");
	printf("8.Exit \n");
	printf("Enter your choice = ");
	scanf("%d",&ch);
	printf("======================================= \n");
	switch(ch)
	{
		case 1:
			printf("\nEnter the value you want to insert = ");
			scanf("%d",&val);
			InsertBegDLL(&head,val);
			printf("After Inserting LinkedList is : ");
			PrintListDLL(head);
			goto loop;
			break;
		case 2:
			printf("\nEnter the value you want to insert = ");
			scanf("%d",&val);
			InsertEndDLL(&head,val);
			printf("After Inserting LinkedList is : ");
			PrintListDLL(head);
			goto loop;
			break;
		case 8:
			printf("===============Thank You=============== \n");
			break;
		default :
			printf("\nWrong input please try again! :( \n");
			goto loop;
			break;
	}
}