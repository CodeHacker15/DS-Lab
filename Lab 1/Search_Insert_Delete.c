#include <stdio.h>
void input(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter a number at position %d = ",i);
		scanf("%d",&a[i]);
	}
}
int find(int a[],int n,int val)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==val)
		{
			return i;
		}
	}
	return -1;
}
int deleteElement(int a[],int n,int val) 
{ 
    int pos=find(a,n,val); 
    if(pos==-1) 
    { 
        printf("Element not found!"); 
        return n;
    } 
    int i; 
    for(i=pos;i<n-1;i++) 
	{
		a[i]=a[i + 1]; 
	}  
    return n-1; 
} 
int insert(int a[],int n,int val,int pos)
{
	int i;
	if(n==pos)
	{
		a[pos]=val;
	}
	else
	{
		for(i=n;i>pos;i--)
		{
			a[i]=a[i-1];
		}
		a[pos]=val;
	}
	return n+1;
}
void show_array(int a[],int n)
{
	int i;
	printf("|");
	for(i=0;i<n;i++)
	{
		printf("%d | ",a[i]);
	}
	printf("\n");
}
void main()
{
	int i,n,val,pos,ch;
	printf("Enter number of elements = ");
	scanf("%d",&n);
	int a[n];
	input(a,n);
	loop:
	printf("========Search/Insert/Delete======== \n");
	printf("1. Search \n");
	printf("2. Insert \n");
	printf("3. Delete \n");
	printf("4. Show Array \n");
	printf("5. Exit \n");
	printf("==================================== \n");
	printf("Enter your choice = ");
	scanf("%d",&ch);
	switch(ch) 
	{
        case 1:
            printf("Enter a number to be searched = ");
			scanf("%d",&val);
			pos=find(a,n,val);
			if(pos==-1)
			{
				printf("Element not present in the array!");
			}
			else
			{
				printf("Element found at position = %d \n",pos);
			}
            goto loop;
        case 2:
            printf("Enter the position at which u want to insert the element = ");
			scanf("%d",&pos);
			if(pos>n)
			{
				printf("Position not possible! \n");
			}
			else
			{
				printf("Enter the value of the element you want to insert = ");
				scanf("%d",&val);
			}
			n=insert(a,n,val,pos);
            goto loop;
        case 3:
			printf("Enter the value to be deleted from the array = ");
			scanf("%d",&val);
			n=deleteElement(a,n,val);
            goto loop;
		case 4:
			show_array(a,n);
			goto loop;
		case 5:
            printf("========Thank You======== \n");
            break;
		default:
            printf("Out of range \n");
            goto loop;
    }
}