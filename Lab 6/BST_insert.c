#include <stdio.h> 
#include <stdlib.h> 
#define COUNT 10
typedef struct tnode 
{ 
     struct tnode* left; 
     int info; 
     struct tnode* right; 
} tnode; 
tnode* createNode(int info) 
{ 
     tnode* new_Node = (tnode*) malloc(sizeof(tnode)); 
     new_Node -> info = info; 
     new_Node -> left = NULL; 
     new_Node -> right = NULL;   
     return(new_Node); 
}    
tnode* insert_nonrecur(tnode* rptr, int val)
{
	if (rptr == NULL)
		rptr = createNode(val);
	else
	{
		tnode *pp = NULL, *ptr=rptr ;
		while ( ptr )
		{
			pp=ptr;
			if (val< ptr -> info)
				ptr=ptr -> left;
			else
				ptr=ptr -> right;
		}
		if (val < pp -> info)
			pp -> left=createNode(val);
		else
			pp -> right=createNode(val);
	}
	return rptr;	
}
void printPostorder(tnode* ptr) 
{ 
     if (ptr == NULL) 
        return;
     printPostorder(ptr -> left);
     printPostorder(ptr -> right);
     printf("%d ", ptr -> info); 
}
void printInorder(tnode* ptr) 
{ 
     if (ptr == NULL) 
          return;
     printInorder(ptr -> left);
     printf("%d ", ptr -> info);
     printInorder(ptr -> right); 
}
void printPreorder(tnode* ptr) 
{
     if (ptr == NULL) 
          return;
     printf("%d ", ptr -> info);
     printPreorder(ptr -> left);
     printPreorder(ptr -> right); 
}
void print2DUtil(tnode *root, int space)  
{  
    if (root == NULL)  
        return;
    space += COUNT;  
    print2DUtil(root->right, space);  
    printf("/n"); 
    for (int i = COUNT; i < space; i++)  
        printf(" ");  
    printf("%d\n",root->info);
    print2DUtil(root->left, space);  
}
void main() 
{ 
	int ch,val;
	tnode *root=NULL;
	loop:
	printf("\n=====Welcome to Menu of Binary Search Tree===== \n");
	printf("1.Insert \n");
	printf("2.Delete \n");
	printf("3.Print Preorder \n");
	printf("4.Print Inorder \n");
	printf("5.Print Postorder \n");
	printf("6.Print List \n");
	printf("7.Exit \n");
	printf("Enter your choice = ");
	scanf("%d",&ch);
	printf("================================================= \n");
	switch(ch)
	{
		case 1:
			po:
			printf("\nEnter the value you want to insert (To Stop Enter '-000') = ");
			scanf("%d",&val);
			if(val == -000)
				goto loop;
			else
				root = insert_nonrecur(root,val);
			goto po;
			break;
		case 2:
			printf("Under Construction!");
			goto loop;
			break;
		case 3:
			printf("\nPreorder traversal of binary tree is \n"); 
			printPreorder(root); 
			goto loop;
			break;
		case 4:
			printf("\nInorder traversal of binary tree is \n"); 
			printInorder(root);
			goto loop;
			break;
		case 5:
			printf("\nPostorder traversal of binary tree is \n"); 
			printPostorder(root);
			goto loop;
			break;
		case 6:
			printf("Under Construction!");
			goto loop;
			break;
		case 7:
			printf("===================Thank You=================== \n");
			break;
	}
}
