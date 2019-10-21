#include<stdio.h>
void Input_Matrix(int A[][10],int r,int c,char alpha)
{
	for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < c;j++)
		{
			printf("Element %c[%d][%d] = ",alpha,i,j);
			scanf("%d",&A[i][j]);
		}
	}
}
void Multiply_Matrices(int A[][10],int m,int n,int B[][10],int l,int o,int mult[][10])
{
	int i,j,k;
	for(i = 0;i < m;i++)
	{
		for(j = 0;j < o;j++)
		{
			mult[i][j] = 0;
			for(k = 0;k < n;++k)
				mult[i][j] = mult[i][j] + A[i][k] * B[k][j];
			printf("|%d|",mult[i][j]);
		}
		printf("\n");
	}
}
void Determinant_Matrix(int D[][10])
{
	long det;
	det = D[0][0]*((D[1][1]*D[2][2]) - (D[2][1]*D[1][2])) -D[0][1]*(D[1][0]*D[2][2] - D[2][0]*D[1][2]) + D[0][2]*(D[1][0]*D[2][1] - D[2][0]*D[1][1]);
  	printf("Determinant of 3X3 matrix: %ld",det);
}
void Sum_Diagonal(int A[][10],int m)
{
	int msum = 0,rsum = 0;
	for (int i = 0; i < m; ++i) 
    {
        msum = msum + A[i][i];
        rsum = rsum + A[i][m - i - 1];
    }
    printf("The sum of the main diagonal elements is = %d \n", msum);
    printf("The sum of the reverse diagonal elements is  = %d \n", rsum);
}
void Sum_Triangle(int A[][10],int r,int c)
{
	int usum = 0,lsum = 0;
	for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < c;j++)
		{
			if(i <= j)
				usum += A[i][j];
			if(j <= i)
				lsum += A[i][j];
		}
	}
	printf("Upper sum is %d \n",usum);
	printf("Lower sum is %d \n",lsum);
}
void Sum_Row(int A[][10],int r,int c)
{
	int sum;
	for(int i = 0;i < r;i++)
	{
		sum = 0;
		for(int j = 0;j < c;j++)
			sum += A[i][j];
		printf("Sum of Row %d = %d \n",i,sum);
	}
}
void Sum_Column(int A[][10],int r,int c)
{
	int sum;
	for(int i = 0;i < r;i++)
	{
		sum = 0;
		for(int j = 0;j < c;j++)
			sum += A[j][i];
		printf("Sum of Column %d = %d \n",i,sum);
	}
}
void Sum_EvenValues(int A[][10],int r,int c)
{
	int sum = 0;
	for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < c;j++)
		{
			if(A[i][j]%2 == 0)
				sum += A[i][j];
		}
	}
	printf("Sum of all even values = %d \n",sum);
}
void Sum_Div(int A[][10],int r,int c,int div)
{
	int sum = 0;
	for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < c;j++)
		{
			if(A[i][j]%div == 0)
				sum += A[i][j];
		}
	}
	printf("Sum of all values divisible by %d = %d \n",div,sum);
}
void Sort_Row(int A[][10],int r,int c)
{
	int temp;
	for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < c;j++) 
        {
            for(int k = i + 1;k < c;k++)
            {
                if(A[i][j] > A[i][k]) 
                {
                    temp =  A[i][j];
                    A[i][j] = A[i][k];
                    A[i][k] = temp;
                }
            }
        }
    }
    printf("After Sorting Each Row, Matrix : \n");
    for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < c;j++) 
        	printf(" %d ",A[i][j]);
        printf("\n");
    }
}
void Sort_Col(int A[][10],int r,int c)
{
	int temp;
	for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < c;j++) 
        {
            for(int k = i + 1;k < c;k++)
            {
                if(A[i][j] > A[k][j]) 
                {
                    temp =  A[i][j];
                    A[i][j] = A[k][j];
                    A[k][j] = temp;
                }
            }
        }
    }
    printf("After Sorting Each Column, Matrix : \n");
    for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < c;j++) 
        	printf(" %d ",A[i][j]);
        printf("\n");
    }
}
void Sort_RowWise(int A[][10],int r,int c)
{
	int temp[r*c],count = 0,t;
	for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < c;j++) 
        {
        	temp[count] = A[i][j];
        	count = count + 1;
        }
    }
	for(int i = 0;i < r*c;i++) 
   	{
        for(int j = i + 1;j < r*c;j++)
        {
            if(temp[i] > temp[j]) 
       		{
                t =  temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
    count = 0;
    for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < c;j++) 
        {
        	A[i][j] = temp[count];
        	count = count + 1;
        }
    }
    printf("After Sorting Row-Wise, Matrix : \n");
    for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < c;j++) 
        {
        	printf("%d",A[i][j]);
        }
        printf("\n");
    }
}
void Sort_ColWise(int A[][10],int r,int c)
{
	int temp[r*c],count = 0,t;
	for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < c;j++) 
        {
        	temp[count] = A[i][j];
        	count = count + 1;
        }
    }
	for(int i = 0;i < r*c;i++) 
   	{
        for(int j = i + 1;j < r*c;j++)
        {
            if(temp[i] > temp[j]) 
       		{
                t =  temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }
    count = 0;
    for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < c;j++) 
        {
        	A[j][i] = temp[count];
        	count = count + 1;
        }
    }
    printf("After Sorting Column-Wise, Matrix : \n");
    for(int i = 0;i < r;i++)
	{
		for(int j = 0;j < c;j++) 
        {
        	printf("%d",A[i][j]);
        }
        printf("\n");
    }
}
void main()
{
	int m,n,l,o,A[10][10],B[10][10],mult[10][10],div,ch;
	loop:
	printf("\n=========Assignment 2D Array=========\n");
	printf("1.Multiplication of 2 Matrices \n");
	printf("2.Determinant of 3 x 3 Matrix \n");
	printf("3.Sum of Diagonal Elements \n");
	printf("4.Sum of Triangle Elements \n");
	printf("5.Sum of each Row \n");
	printf("6.Sum of each Column \n");
	printf("7.Sum of all Even Values \n");
	printf("8.Sum of all values divisble by n \n");
	printf("9.Sort each Row of Matrix \n");
	printf("10.Sort each Column of Matrix \n");
	printf("11.Sort Matrix Row-Wise \n");
	printf("12.Sort Matrix Column-Wise \n");
	printf("Enter your choice = ");
	scanf("%d",&ch);
	printf("=======================================\n");
	switch(ch)
	{
		case 1:
			printf("Enter row and column of Matrix 1 (row col) = ");
			scanf("%d %d",&m,&n);
			Input_Matrix(A,m,n,'A');
			printf("Enter row and column of Matrix 2 (row col) = ");
			scanf("%d %d",&l,&o);
			Input_Matrix(B,m,n,'B');
			if(n==l)
			{
				printf("Multiplication of Matrix A x B is : \n");
				Multiply_Matrices(A,m,n,B,l,o,mult);
			}
			else
				printf("Multiplication not possible please keep col of matrix 1 and row of matrix 2 same! \n");
			goto loop;
			break;
		case 2:
			Input_Matrix(A,3,3,'D');
			Determinant_Matrix(A);
			goto loop;
			break;
		case 3:
			printf("Enter row and column of Matrix (row col) = ");
			scanf("%d %d",&m,&n);
			Input_Matrix(A,m,n,'S');
			Sum_Diagonal(A,m);
			goto loop;
			break;
		case 4:
			printf("Enter row and column of Matrix (row col) = ");
			scanf("%d %d",&m,&n);
			Input_Matrix(A,m,n,'T');
			Sum_Triangle(A,m,n);
			goto loop;
			break;
		case 5:
			printf("Enter row and column of Matrix (row col) = ");
			scanf("%d %d",&m,&n);
			Input_Matrix(A,m,n,'R');
			Sum_Row(A,m,n);
			goto loop;
			break;
		case 6:
			printf("Enter row and column of Matrix (row col) = ");
			scanf("%d %d",&m,&n);
			Input_Matrix(A,m,n,'C');
			Sum_Column(A,m,n);
			goto loop;
			break;
		case 7:
			printf("Enter row and column of Matrix (row col) = ");
			scanf("%d %d",&m,&n);
			Input_Matrix(A,m,n,'E');
			Sum_EvenValues(A,m,n);
			goto loop;
			break;
		case 8:
			printf("Enter row and column of Matrix (row col) = ");
			scanf("%d %d",&m,&n);
			Input_Matrix(A,m,n,'D');
			printf("Enter value of n = ");
			scanf("%d",&div);
			Sum_Div(A,m,n,div);
			goto loop;
			break;
		case 9:
			printf("Enter row and column of Matrix (row col) = ");
			scanf("%d %d",&m,&n);
			Input_Matrix(A,m,n,'R');
			Sort_Row(A,m,n);
			goto loop;
			break;
		case 10:
			printf("Enter row and column of Matrix (row col) = ");
			scanf("%d %d",&m,&n);
			Input_Matrix(A,m,n,'C');
			Sort_Col(A,m,n);
			goto loop;
			break;
		case 11:
			printf("Enter row and column of Matrix (row col) = ");
			scanf("%d %d",&m,&n);
			Input_Matrix(A,m,n,'R');
			Sort_RowWise(A,m,n);
			goto loop;
			break;
		case 12:
			printf("Enter row and column of Matrix (row col) = ");
			scanf("%d %d",&m,&n);
			Input_Matrix(A,m,n,'C');
			Sort_ColWise(A,m,n);
			goto loop;
			break;
	}
}