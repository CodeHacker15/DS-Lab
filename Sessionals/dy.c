#include<stdio.h>
#include<stdlib.h>
void main()
{
	int i,j;
	int r=2,c=3;
	int count = 0;
	int *ar = (int *)malloc(4*4*sizeof(int));
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			*(ar + i*r + j*c) = ++count; 
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("|%d|",*(ar + i*r + j*c));
		}
		printf("\n");
	}
}