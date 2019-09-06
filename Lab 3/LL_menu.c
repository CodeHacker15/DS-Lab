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
	new_node -> next = *h;
	*h=new_node;
}
void InsertLastSLL(struct Node **h,int val)
{
	struct Node* last = *h;
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node -> info = val;
	new_node -> next = NULL;
	if(*h == NULL) 
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
int InsertPosSLL(struct Node **h,int val,int pos)
{
	int count = 0,i;
	struct Node* temp = *h;
	struct Node* posptr = *h;
	while(temp!= NULL)
	{
		temp = temp -> next;
		 ++count;
	}
	if(pos>count+1)
	{
		printf("Insertion at this position is not possible \n");
		free(temp);
		return -8989;
	}
	else
	{
		struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
		new_node -> info = val;
		new_node -> next = NULL;
		for(i=1;i<pos-1;i++)
		{
			posptr = posptr -> next;
		}
		new_node -> next = posptr -> next;
		posptr -> next = new_node;
	}
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
			InsertBegSLL(&head,val);
			printf("After Inserting LinkedList is : ");
			PrintListSLL(head);
			goto loop;
			break;
		case 2:
			printf("\nEnter the value you want to insert = ");
			scanf("%d",&val);
			InsertLastSLL(&head,val);
			printf("After Inserting LinkedList is : ");
			PrintListSLL(head);
			goto loop;
			break;
		case 3:
			printf("\nEnter the value you want to insert = ");
			scanf("%d",&val);
			printf("Enter the position you want the value to be inserted at = ");
			scanf("%d",&pos);
			delval = InsertPosSLL(&head,val,pos);
			if(delval != -8989)
			{
				printf("After Inserting LinkedList is : ");
				PrintListSLL(head);
			}
			goto loop;
			break;
		case 4:
			printf("\nDeleting First Element of LinkedList.... \n");
			delval = DeleteBegSLL(&head);
			if(delval != -8989)
			{
				printf("After Deleting LinkedList is : ");
				PrintListSLL(head);
			}
			printf("\nDeleted element is = %d ",delval);
			goto loop;
			break;
		case 5:
			printf("\nDeleting Last Element of LinkedList.... \n");
			delval = DeleteLastSLL(&head);
			printf("After Deleting LinkedList is : ");
			PrintListSLL(head);
			printf("\nDeleted element is = %d ",delval);
			goto loop;
			break;
		case 7:
			printf("\nShowing LinkedList : \n");
			PrintListSLL(head);
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