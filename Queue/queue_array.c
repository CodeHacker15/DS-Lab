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
	if(f == -1)
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
void delete()
{
	if(f == -1)
	{
		printf("Underflow!");
		return;
	}
	printf("Element deleted from queue is : %d\n",q[f]);
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
}
void display()
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
	printf("\n");
}
void main()
{
	insert(10);
	insert(20);
	insert(30);
	display();
	delete();
	delete();
	insert(2);
	display();
}
