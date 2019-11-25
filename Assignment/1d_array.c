#include<stdio.h>
#include<math.h>
float mean = 0,var = 0,st = 0;
void InputArray(int A[],int n)
{
	for(int i = 0;i < n;i++)
	{
		printf("Element [%d] = ",i);
		scanf("%d",&A[i]);
	}
}
int SumArray(int A[],int n)
{
	int sum = 0;
	for(int i = 0;i < n;i++)
	{
		sum = sum + A[i];
	}
	return sum;
}
int Sum(int A[],int n,int sum)
{
	printf("[");
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			if((A[i] + A[j] == sum))
			{
				printf("( %d, %d)",A[i],A[j]);
			}
		}
	}
	printf("]");
}
void Frequency(int F[],int n)
{
	int m = 0;
    for(int i = 0;i < n;i++)
    {
        printf("Enter Marks of Student %d = ",i+1);
        scanf("%d",&m);
        F[m] = F[m] + 1;
    }
    for(int i = 0;i <= 10;i++)
    {
        printf("\nFrequency of %d is: %d",i,F[i]);
    }
}
void arr_mean(float a[], int n)
{
    for(int i = 0;i < n;i++)
        mean = mean + a[i];
    mean = mean/n;
    printf("Mean = %f\n",mean);
}
void arr_varience(float a[], int n)
{
    for(int i = 0;i < n;i++)
        var = var + pow(mean-a[i],2);
    var = var/n;
    printf("Varience = %f\n",var);
}
void arr_std_dev(float a[], int n)
{
    st = sqrt(var);
    printf("Standard deviation = %f\n",st);
}
void main()
{
	int A[50] = {0};
	int n;
	Frequency(A,10);
}