#include<stdbool.h> 
#include<stdlib.h>
#include<stdio.h>
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

struct bst_node *find_min(struct bst_node *root)
{
		while(root->left!=NULL)
				root=root->left;

		return root; 
}

struct bst_node *delete(struct bst_node *root, int data)
{
		if(root==NULL)
				return root; 
		else if(data>root->data)
				root->right=delete(root->right, data); 
		else if(data<root->data)
				root->left=delete(root->left, data); 
		else
		{
				if(root->left==NULL && root->right==NULL)
				{
						free(root); 
						root=NULL; 
				}

				else if(root->left==NULL)
				{
						struct bst_node *temp = root; 
						root=root->right; 
						free(temp); 
				}

				else if(root->right==NULL)
				{
						struct bst_node *temp=root; 
						root=root->left; 
						free(temp); 
				}

				else
				{
						struct bst_node *temp=find_min(root->right); 
						root->data=temp->data; 
						root->right=delete(root->right, temp->data);
				}

		}
		return root; 
}

struct bst_node *search_node(struct bst_node *root, int data)
{		
		if(root==NULL)
				return NULL; 
		else if(root->data==data)
				return root; 
		else if(data>root->data)
				return search_node(root->right, data); 
		else
				return search_node(root->left, data);
}

void pre_order(struct bst_node *root)
{
		if(root==NULL)
				return; 
		printf("%d ", root->data); 
		pre_order(root->left); 
		pre_order(root->right);
}

void in_order(struct bst_node *root)
{
		if(root==NULL)
				return;
		in_order(root->left); 
		printf("%d ", root->data); 
		in_order(root->right); 
}

void post_order(struct bst_node *root)
{
		if(root==NULL)
				return; 
		post_order(root->left); 
		post_order(root->right); 
		printf("%d ", root->data); 
}

struct bst_node **create_queue(int *rear, int *front)
{
		struct bst_node **queue=(struct bst_node **)calloc(MAX_SIZE, sizeof(struct bst_node *));
		(*rear)=(*front)=0; 
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
		int rear, front;
		struct bst_node **queue = create_queue(&rear, &front); 
		struct bst_node *temp=root; 
		
		while(temp)
		{
				printf("%d ", temp->data);

				if(temp->left)
						enqueue(queue, &rear, temp->left); 
				if(temp->right)
						enqueue(queue, &rear, temp->right); 

				temp=dequeue(queue, &front); 
		}

}

int height(struct bst_node *root)
{
		if(root==NULL)
				return -1; 
		int left = height(root->left); 
		int right = height(root->right); 
													
		int height = (left>right)? left+1 : right+1;

		return height; 
}

