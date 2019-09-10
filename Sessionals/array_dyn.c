#include<stdio.h>
#include<stdlib.h>
void input(int a[][4],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter a number at position (%d,%d) = ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
int shift_diag(int sa[],int a[][4])
{
	int i,j=0,k=0;
	for(i=0;i<10;i++)
	{
		if(i<3)
		{
			sa[i] = a[i+1][i];
		}
		else if(i<7)
		{
			sa[i] = a[j][j];
			j=j+1;
		}
		else
		{
			sa[i] = a[k][k+1];
			k=k+1;
		}
	}
}
void main()
{
	int i;
	int a[4][4];
	input(a,4,4);
	int *sa = (int *)malloc(10*sizeof(int));
	shift_diag(sa,a);
	for(i=0;i<10;i++)
	{
		printf("|%d|",sa[i]);
	}
}