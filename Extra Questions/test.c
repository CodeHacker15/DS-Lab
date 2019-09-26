#include<stdio.h>
#include<string.h>
void main()
{
	int n,i;
	scanf("%d",&n);
	char string[26];
	char *arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%s",string);
		arr[i]=string;
	}
	for(i=0;i<n;i++)
	{
		printf("%s",arr[i]);
	}
}