#include <stdio.h>
void main()
{
	int n;
	float avg=0,sum=0;
	printf("Enter the no of integer values you want to find sum and average of = ");
	scanf("%d",&n);
	int ar[n];
	printf("Enter value of array elements : \n");
	for(int i =0;i<n;i++)
	{
		printf("Element %d = ",i+1);
		scanf("%d",&ar[n]);
		sum+=ar[n];		
	}
	avg=sum/n;  
	printf("Sum of elements in the given array is = %f \n",sum);
	printf("Average of elements in the given array is = %f ",avg);
}