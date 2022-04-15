#include<stdio.h> 
#include<stdlib.h> 
struct node				 
{						
	int data; 
	struct node *left; 
	struct node *right; 
};
typedef struct node BstNode; 
BstNode *insert(BstNode *, int); 
BstNode *new_node(int data); 
int main()
{
	BstNode *root=NULL; 
	root=insert(root, 30); 
	root=insert(root, 50); 
	root=insert(root, 10); 
}
									
BstNode *new_node(int data)
{
	BstNode *node=(BstNode*)malloc(sizeof(BstNode)); 
	node->data=data; 
	node->right=node->left=NULL; 
	return node;
}			
						
BstNode *insert(BstNode *root, int data)
{			
	if(root==NULL)							
		root=new_node(data);
					
	else if(data>root->data)
		root->right=insert(root->right, data); 
						
	else
		root->left=insert(root->left, data); 
		
	return root;								}

