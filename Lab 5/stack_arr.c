#include<stdio.h>
#define MAX 5
int q[MAX];
int f = -1;
int r = -1;
void push(int val)
{
	if(r == MAX - 1)
	{
		printf("Overflow!");
		return;
	}
	else
	{
		
		r = r + 1;
		q[r] = val;
	}
	if(f == -1)
		f = 0;
	printf("%d %d",f,r);
}
int pop()
{
	int val;
	if(r == -1)
	{
		printf("Underflow!");
		return -8989;
	}
	else
	{
		val = q[f];
		f = f + 1;
		printf("%d %d",f,r);
		return val;
	}
}
void show()
{
	int i;
	printf("%d %d",f,r);
	for(i = f;i <= r;i++)
	{
		printf("| %d |",q[i]);
	}
}
void main()
{
	
	int val,ch;
	loop:
	printf("\n=====Welcome to Queue Push/Pop===== \n");
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
			push(val);
			goto loop;
			break;
		case 2:
			val = pop();
			if(val != -8989)
				printf("Value poped is = %d",val);
			goto loop;
			break;
		case 3:
			show();
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