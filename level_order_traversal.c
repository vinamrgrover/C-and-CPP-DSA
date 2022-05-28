#include<stdio.h>
#include<stdlib.h> 
#define MAX_SIZE 20 
struct bst_node
{
		int data;
		struct bst_node *left; 
		struct bst_node *right; 
}; 
struct bst_node *new_node(int data)
{
		struct bst_node *node=(struct bst_node *)malloc(sizeof(struct bst_node)); 
		node->data=data; 
		node->left=node->right=NULL; 
		return node; 
}
struct bst_node *insert(struct bst_node *root, int data)
{
		if(root==NULL)
				root=new_node(data); 
		else if(data>root->data)
				root->right=insert(root->right, data); 
		else
				root->left=insert(root->left, data); 

		return root; 
}
struct bst_node **create_queue(int *rear, int *front)
{																									
		struct bst_node **queue=(struct bst_node **)calloc(MAX_SIZE, sizeof(struct bst_node *)); 
		(*rear) = (*front) = 0; 
		return queue; 
}
void enqueue(struct bst_node **queue, int *rear, struct bst_node *new_node)
{
		queue[*rear]=new_node; 
		++(*rear); 
}
struct bst_node *dequeue(struct bst_node **queue, int *front)
{
		++(*front); 
		return queue[(*front)-1]; 
}
void level_order(struct bst_node *root)
{
		int front, rear; 
		struct bst_node **queue=create_queue(&rear, &front); 

		struct bst_node *temp = root; 

		while(temp)
		{					
				printf("%d ", temp->data); 

				if(root->left)
						enqueue(queue, &rear, temp->left); 
				if(root->right)
						enqueue(queue, &rear, temp->right); 

				temp=dequeue(queue, &front); 
		}

		printf("\n"); 
}
int main()
{
		struct bst_node *root = NULL; 
		root=insert(root, 30); 
		root=insert(root, 10);
		root=insert(root, 50); 
		root=insert(root, 5); 
		root=insert(root, 15); 
		root=insert(root, 40); 
		root=insert(root, 80); 
		level_order(root); 

		return 0; 
}



