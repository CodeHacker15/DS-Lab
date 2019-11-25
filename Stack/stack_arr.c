#include<stdio.h>
#define MAX 10
int STACK[MAX],TOP = -1;
void PUSH(int stack[],int item)
{
    if(TOP==MAX-1)
    {
        printf("\nSTACK is FULL CAN't ADD ITEM\n");
        return;
    }
    TOP++;
    stack[TOP]=item;
}
void POP(int stack[])
{
    int deletedItem;
    if(TOP==-1)
    {
        printf("STACK is EMPTY.\n");
        return;
    }
 
    deletedItem=stack[TOP];
    TOP--;
    printf("%d deleted successfully\n",deletedItem);
    return;
}
void display(int stack[])
{
    int i=0;
    if(TOP==-1)
    {
        printf("Stack is Empty .\n");
        return;
    }
 
    printf("%d <-- TOP ",stack[TOP]);
    for(i=TOP-1;i > -1;i--)
    {
        printf("\n%d",stack[i]);
    }
    printf("\n\n");
}
void main()
{
	int val,ch;
	loop:
	printf("\n=====Welcome to Stack Push/Pop===== \n");
	printf("1.Push Element \n");
	printf("2.Pop Element \n");
	printf("3.Display Stack \n");
	printf("4.Exit \n");
	printf("Enter your choice = ");
	scanf("%d",&ch);
	printf("======================================= \n");
	switch(ch)
	{
		case 1:
			printf("Enter value to be pushed = ");
			scanf("%d",&val);
			PUSH(STACK,val);
			goto loop;
			break;
		case 2:
			POP(STACK);
			goto loop;
			break;
		case 3:
			display(STACK);
			goto loop;
			break;
		case 4:
			printf("===============Thank You=============== \n");
			break;
		default :
			printf("\nWrong input please try again! :( \n");
			goto loop;
			break;
	}
}