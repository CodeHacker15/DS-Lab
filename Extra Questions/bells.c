#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b)
	{
		if(a>c)
			printf("%d",b+c);
		else
			printf("%d",a+b);
	}
	else if(b>c)
		printf("%d",a+c);
	else
		printf("%d",b+a);
	return 0;
}