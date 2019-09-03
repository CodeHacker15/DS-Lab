#include <stdio.h> 
#include <stdlib.h>
struct Node
	{
		int info;
		struct Node *next;
	};
void InsertBegSLL(struct Node **h,int val)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node -> info = val;
	new_node -> next = NULL;
	new_node -> next = *h;
	*h=new_node;
}
void InsertLastSLL(struct Node **h,int val)
{
	struct Node* last = *h;
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node -> info = val;
	new_node -> next = NULL;
	if(*h== NULL) 
    { 
      *h = new_node;
	  return;
	}
	while(last -> next != NULL)
	{
		last = last -> next;
	}
	last -> next = new_node;
	return;
}
int DeleteBegSLL(struct Node **h)
{
	int val;
	if(*h == NULL)
	{
		printf("Underflow! \n");
		return -8989;
	}
	else
	{
		struct Node* del_ptr = *h;
		val = del_ptr -> info ;
		*h = del_ptr -> next;
		del_ptr -> next = NULL;
		free(del_ptr);
		del_ptr = NULL;
		return val;
	}	
}
int DeleteLastSLL(struct Node **h)
{
	int val;
	struct Node* sptr = *h;
	struct Node* ptr;
	while(sptr -> next != NULL)
	{
		ptr = sptr;
		sptr = sptr -> next;
	}
	val = ptr -> info;
	free(sptr -> next);
	ptr -> next = NULL;
	return val;
}
void PrintListSLL(struct Node *node) 
{ 
  while(node != NULL) 
  { 
     printf("| %d |", node -> info); 
     node = node -> next; 
  } 
  printf("\n");
}
void main()
{	
	int ch,val,delval;
	struct Node *head=NULL;
	loop:
	printf("\n=====Welcome to LinkList Insertion===== \n");
	printf("1.Insert at beginning \n");
	printf("2.Insert at last \n");
	printf("3.Delete at beginning \n");
	printf("4.Delete at last \n");
	printf("5.Print List \n");
	printf("6. Exit \n");
	printf("Enter your choice = ");
	scanf("%d",&ch);
	printf("======================================= \n");
	switch(ch)
	{
		case 1:
			printf("Enter the value you want to insert = ");
			scanf("%d",&val);
			InsertBegSLL(&head,val);
			printf("\nAfter Inserting LinkedList is : ");
			PrintListSLL(head);
			goto loop;
			break;
		case 2:
			printf("Enter the value you want to insert = ");
			scanf("%d",&val);
			InsertLastSLL(&head,val);
			printf("\nAfter Inserting LinkedList is : ");
			PrintListSLL(head);
			goto loop;
			break;
		case 3:
			printf("Deleting First Element of LinkedList.... \n");
			delval = DeleteBegSLL(&head);
			if(delval != -8989)
			{
				printf("\nAfter Deleting LinkedList is : ");
				PrintListSLL(head);
			}
			printf("\n Deleted element is = %d ",delval);
			goto loop;
			break;
		case 4:
			printf("Deleting Last Element of LinkedList.... \n");
			delval = DeleteLastSLL(&head);
			printf("\nAfter Deleting LinkedList is : ");
			PrintListSLL(head);
			printf("\n Deleted element is = %d ",delval);
			goto loop;
			break;
		case 5:
			printf("Showing LinkedList : \n");
			PrintListSLL(head);
			goto loop;
			break;
		case 6:
			printf("===============Thank You=============== \n");
			break;
		default :
			printf("Wrong input please try again! :( \n");
			goto loop;
			break;
	}
}