#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;	
};
void push(struct Node **h, int x) 
{ 
    struct Node *temp = (struct Node *)malloc(sizeof(*temp)); 
    temp -> data = x; 
    temp -> next = *h; 
    *h = temp; 
}
int pop(struct Node **h) 
{ 
    int del; 
    struct Node *temp; 
    del = (*h) -> data; 
    temp = *h; 
    (*h) = (*h) -> next; 
    free(temp); 
    return del; 
} 
int length_rec(struct Node *h,int x)
{
	int count = x;
	if(h == NULL)
		return count;
	else
	{
		count = count + 1;
		length_rec(h -> next,count);
	}
}
int length_itt(struct Node *h)
{
	int count = 0;
	while(h != NULL)
	{
		count = count + 1;
		h = h -> next;
	}
	return count;
}
void main()
{
	int ch,val;
    struct Node *head = NULL;
    loop:
    printf("=========Length of Linked List========= \n");
	printf("1. Push \n");
	printf("2. Pop \n");
	printf("3. Length Using Recursive Function \n");
	printf("4. Length Using Iterative Function \n");
	printf("5. Exit \n");
	printf("======================================= \n");
	printf("Enter your choice = ");
	scanf("%d",&ch);
	printf("\n");
	switch(ch)
	{ 
		case 1:
			printf("Enter value you want to push in Node = ");
			scanf("%d",&val);
    		push(&head,val);
    		goto loop; 
    	case 2:
    		val = pop(&head);
    		printf("Value poped is = %d",val);
    		goto loop;
    	case 3:
    		val = length_rec(head,0);
    		printf("Length using Recursive Function = %d \n",val);
    		goto loop;
    	case 4:
    		val = length_itt(head);
    		printf("Length using Iterative Function = %d \n",val);
    		goto loop;
    	case 5:
    		break;
    	default:
            printf("Out of range \n");
            goto loop;
    }
}

