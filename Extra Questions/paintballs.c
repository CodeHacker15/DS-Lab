#include<stdio.h>
void main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	long val = m;
	n = n - 1;
	while(n>0)
	{
		val = val * (m-1);
		--n;
	}
	printf("%lld",val);
}