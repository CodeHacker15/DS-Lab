#include<stdio.h>
#include<stdlib.h>
struct stack 
{ 
    int data; 
    struct stack *next; 
};
void push(struct stack **s, int x) 
{ 
    struct stack *p = (struct stack *)malloc(sizeof(*p)); 
    p -> data = x; 
    p -> next = *s; 
    *s = p; 
}
int pop(struct stack **s) 
{ 
    int del; 
    struct stack *temp; 
    del = (*s) -> data; 
    temp = *s; 
    (*s) = (*s) -> next; 
    free(temp); 
    return del; 
} 
int top(struct stack *s) 
{ 
    return (s -> data); 
}
void SortInsert(struct stack **s, int x) 
{
    if(*s == NULL || x < top(*s)) 
    { 
        push(s,x); 
        return; 
    } 
    int temp = pop(s); 
    SortInsert(s,x);
    push(s, temp); 
} 
void RecSort(struct stack **s) 
{  
    if(*s != NULL) 
    { 
        int x = pop(s);
        RecSort(s); 
		SortInsert(s,x); 
    } 
}
void printStack(struct stack *s) 
{ 
    while(s != NULL) 
    { 
        printf("| %d |", s -> data); 
        s = s -> next; 
    } 
    printf("\n"); 
} 
void main()
{
	int ch,val;
    struct stack *top = NULL;
    loop:
    printf("=========Sorting Stack Menu========= \n");
	printf("1. Push \n");
	printf("2. Pop \n");
	printf("3. Sort \n");
	printf("4. Show Stack \n");
	printf("5. Exit \n");
	printf("==================================== \n");
	printf("Enter your choice = ");
	scanf("%d",&ch);
	printf("\n");
	switch(ch)
	{ 
		case 1:
			printf("Enter value you want to push in stack = ");
			scanf("%d",&val);
    		push(&top,val);
    		goto loop; 
    	case 2:
    		val = pop(&top);
    		printf("Value poped is = %d",val);
    		goto loop;
    	case 3:
    		RecSort(&top);
    		printf("Stack elements after sorting:\n"); 
    		printStack(top);
    		goto loop;
    	case 4:
    		printStack(top);
    		goto loop;
    	case 5:
    		break;
    	default:
            printf("Out of range \n");
            goto loop;
    } 
     
}