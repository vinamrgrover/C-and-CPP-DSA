#include<stdio.h> 
#include<stdbool.h> 
#include<stdlib.h> 
struct node			
{							
	int data; 
	struct node *left;
	struct node *right; 
}; 				
typedef struct node BstNode; 
BstNode *insert(BstNode *, int);
BstNode *New_Node(int data);			
bool Search_Node(BstNode *, int);					 	
int main()									
{									
	BstNode *root=NULL; 
	root=insert(root, 30); 						
	root=insert(root, 50); 							
	root=insert(root, 10); 							
	/*Search_Node function will  return true if the node is present
	  in the BST; If not, then it would return false */			
	if(Search_Node(root, 10)==true) 
		printf("FOUND\n"); 
	else					
		printf("NOT FOUND\n"); 	
	
}
BstNode *insert(BstNode *root, int data)
{					
	if(root==NULL)
		root=New_Node(data); 

	else if(data>root->data)
		root->right=insert(root->right, data); 
	else 
		root->left=insert(root->left, data); 

	return root; 	
		 								
}			
	
BstNode *New_Node(int data)
{					
	BstNode *node=(BstNode*)malloc(sizeof(BstNode)); 
	node->data=data; 
	node->left=node->right=NULL; 
	return node; 
}

bool Search_Node(BstNode *root, int data)
{				
	if(root==NULL)			
		return false; 	
	if(root->data==data)
		return true; 
	else if(data>root->data)			
  		return Search_Node(root->right, data); 
	else 	
		return Search_Node(root->left, data); 
}

