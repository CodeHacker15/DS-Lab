#include <stdio.h> 
#include <stdlib.h> 
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
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    print2DUtil(root->right, space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->data<<"\n";  
  
    // Process left child  
    print2DUtil(root->left, space);  
}  
  
// Wrapper over print2DUtil()  
void print2D(tnode *root)  
{  
    // Pass initial space count as 0  
    print2DUtil(root, 0);  
}  
void main() 
{ 
	tnode *root=NULL;
	/*printf("\n=====Welcome to LinkList Insertion===== \n");
	printf("1.Insert \n");
	printf("2.Delete \n");
	printf("3.Print Preorder \n");
	printf("4.Print Inorder \n");
	printf("5.Print Postorder \n");
	printf("7.Print List \n");
	printf("8.Exit \n");
	printf("Enter your choice = ");
	scanf("%d",&ch);
	printf("======================================= \n");
	switch(ch)
	printf("\nPreorder traversal of binary tree is \n"); 
	printPreorder(root); 
	printf("\nInorder traversal of binary tree is \n"); 
	printInorder(root);   
	printf("\nPostorder traversal of binary tree is \n"); 
	printPostorder(root);*/
	insert_nonrecur(root,1);
	insert_nonrecur(root,2);
	insert_nonrecur(root,3);
	insert_nonrecur(root,4);
	insert_nonrecur(root,5);
	insert_nonrecur(root,6);
	insert_nonrecur(root,7);
	insert_nonrecur(root,8);
	print2D(root);
} 
/* Given a binary tree, print its nodes according to the 
  "bottom-up" postorder traversal. */


