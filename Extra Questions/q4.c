#include<stdio.h>
#include <stdlib.h>
struct Node	
{
	int info;
	struct Node *next;
};
void insert(struct Node **h,int val)
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
void regre(struct Node *node)
{
	struct Node* temp;
	while(node->next!=NULL)
	{
		if(node -> info > node -> next -> info)
		{
			printf("%d -> ",node->info);
			node = node -> next;
		}
		else
		{
			node = node -> next;
		}
	}
	printf("%d",node->info);
}
void main()
{
	int i,n,val;
	struct Node *head=NULL;
	printf("How many times values do you want in your list? = ");
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		printf("Value %d = ",i);
		scanf("%d",&val);
		insert(&head,val);
	}
	regre(head);
}
	