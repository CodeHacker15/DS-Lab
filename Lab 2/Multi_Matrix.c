#include<stdio.h>
void input_matrix(int m1[][10],int r1,int c1,int m2[][10],int r2,int c2)
{
	int i,j;
	printf("====Matrix 1==== \n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("Element [%d][%d] = ",i,j);
			scanf("%d",&m1[i][j]);
		}
	}
	printf("====Matrix 2==== \n");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("Element [%d][%d] = ",i,j);
			scanf("%d",&m2[i][j]);
		}
	}
}
void multimatrix(int m1[][10], int m2[][10], int mult[][10], int r1, int c1, int r2, int c2)
{
	int i,j,k;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			mult[i][j]=0;
			for(k=0;k<c1;++k)
			{
				mult[i][j]=mult[i][j]+m1[i][k]*m2[k][j];
			}
		}
	}
}
void display(int mult[][10],int r1,int c2)
{
	int i,j;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("|%d|",mult[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	int r1,c1,r2,c2,m1[10][10],m2[10][10],mult[10][10];
	loop:
	printf("Enter row and column of Matrix 1 (row col) = ");
	scanf("%d %d",&r1,&c1);
	printf("Enter row and column of Matrix 2 (row col) = ");
	scanf("%d %d",&r2,&c2);
	if(c1==r2)
	{
		input_matrix(m1,r1,c1,m2,r2,c2);
	}
	else
	{
		printf("Multiplication not possible please keep col of matrix 1 and row of matrix 2 same! \n");
		goto loop;
	}
	multimatrix(m1,m2,mult,r1,c1,r2,c2);
	display(mult,r1,c2);
}