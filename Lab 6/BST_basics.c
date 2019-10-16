#include <stdio.h> 
#include <stdlib.h> 
  
/* A binary tree node has info, pointer to left child 
   and a pointer to right child */
typedef struct tnode 
{ 
     struct tnode* left; 
     
     int info; 
    
     struct tnode* right; 
} tnode; 
  
/* Helper function that allocates a new node with the 
   given info and NULL left and right pointers. */
tnode* createNode(int info) 
{ 
     tnode* new_Node = (tnode*) malloc(sizeof(tnode)); 
     new_Node->info = info; 
     new_Node->left = NULL; 
     new_Node->right = NULL; 
  
     return(new_Node); 
} 
  
/* Given a binary tree, print its nodes according to the 
  "bottom-up" postorder traversal. */
void printPostorder(tnode* ptr) 
{ 
     if (ptr == NULL) 
        return; 
  
     // first recur on left subtree 
     printPostorder(ptr->left); 
  
     // then recur on right subtree 
     printPostorder(ptr->right); 
  
     // now deal with the ptr 
     printf("%d ", ptr->info); 
} 
  
/* Given a binary tree, print its nodes in inorder*/
void printInorder(tnode* ptr) 
{ 
     if (ptr == NULL) 
          return; 
  
     /* first recur on left child */
     printInorder(ptr->left); 
  
     /* then print the info of ptr */
     printf("%d ", ptr->info);   
  
     /* now recur on right child */
     printInorder(ptr->right); 
} 
  
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(tnode* ptr) 
{ 
     if (ptr == NULL) 
          return; 
  
     /* first print info of ptr */
     printf("%d ", ptr->info);   
  
     /* then recur on left sutree */
     printPreorder(ptr->left);   
  
     /* now recur on right subtree */
     printPreorder(ptr->right); 
}     
/* Driver program to test above functions*/
int main() 
{ 
     tnode *root=NULL;
     
     root = createNode(1); 
     root->left             = createNode(2); 
     root->right           = createNode(3); 
     root->left->left     = createNode(4); 
     root->left->right   = createNode(5);  
  
     printf("\nPreorder traversal of binary tree is \n"); 
     printPreorder(root); 
  
     printf("\nInorder traversal of binary tree is \n"); 
     printInorder(root);   
  
     printf("\nPostorder traversal of binary tree is \n"); 
     printPostorder(root); 
  
  
     return 0; 
} 

