#include<stdio.h>
#define MAX 5
int q[MAX];
int f = -1;
int r = -1;
void insert(int val)
{
	if((f == 0 && r == MAX-1) || (f == r+1))
	{
		printf("Overflow!");
		return;
	}
	if
	{
		f = 0;
		r = 0;
	}
	else
	{
		if(r == MAX-1)
			r = 0;
		else
			r = r + 1;
	}
	q[r] = val;
}
int delete()
{
	int val;
	if(f == -1)
	{
		printf("Underflow!");
		return -8989;
	}
	val = q[f];
	if(f == r)
	{
		f = -1;
		r = -1;
	}
	else
	{	
		if(f == MAX-1)
			f = 0;
		else
			f = f + 1;
	}
	return val;
}
void show()
{
	int fp = f,rp = r;
	if(f == -1)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n");
	if(fp <= rp)
	{
		while(fp <= rp)
		{
			printf("%d ",q[fp]);
			fp++;
		}
	}
	else
	{
		while(fp <= MAX-1)
		{
			printf("%d ",q[fp]);
			fp++;
		}
		fp = 0;
		while(fp <= rp)
		{
			printf("%d ",q[fp]);
			fp++;
		}
	}
}
void main()
{
	
	int val,ch;
	loop:
	printf("\n=====Welcome to Queue Push/Pop===== \n");
	printf("1.Insert Element \n");
	printf("2.Delete Element \n");
	printf("3.Display Queue \n");
	printf("4.Exit \n");
	printf("Enter your choice = ");
	scanf("%d",&ch);
	printf("======================================= \n");
	switch(ch)
	{
		case 1:
			printf("Enter value to be inserted = ");
			scanf("%d",&val);
			push(val);
				printf("Value deleted is = %d",val);
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