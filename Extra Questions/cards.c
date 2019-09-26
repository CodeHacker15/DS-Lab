#include<stdio.h>
int main()
{
	int n,a,i,sum=0;
	scanf("%d %d",&n,&a);
	int temp[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp[i]);
	}
	for(i=0;i<n;i++)
	{
		sum = sum + temp[i];
	}
	if(a*n > sum)
		printf("0");
	else if(a*n == sum)
		printf("1");
	else 
		printf("34");
	return 0;
}
	
	