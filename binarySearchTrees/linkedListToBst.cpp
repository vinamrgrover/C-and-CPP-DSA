#include<iostream> 
using namespace std; 
class node
{						
public:
		int data; 
		node *next; 
}; 

class bstNode
{
public:
		int data;
		bstNode *left; 
		bstNode *right; 
}; 


void insertNode(node **head, int data)
{
		node *new_node = new node; 

		new_node -> data = data; 
										
		if(!(*head))
		{
				*head = new_node; 
				new_node -> next = NULL; 
				return; 
		}

		new_node -> next = *head; 
		*head = new_node; 
}
									
int countNodes(node *Node)
{
		int count = 0; 

		while(Node)
		{
				++count; 
				Node = Node -> next;
		}

		return count; 
}

bstNode *newBstNode(int data)
{
		bstNode *new_node = new bstNode; 

		new_node -> data = data; 
		new_node -> left = new_node -> right = NULL; 
		return new_node; 
}

							
bstNode *listToBstUtil(node **head, int n)
{						
		if(n<=0)
				return NULL; 
											
		bstNode *left = listToBstUtil(head, n/2); // left sub-tree will contain n/2 nodes

		bstNode *root = newBstNode((*head) -> data); // creating root node
										
		root -> left = left; // updating left child

		*head = (*head) -> next; // updating head
																													
		root -> right = listToBstUtil(head, (n - n/2) -1); // total nodes - nodes in the left tree - 1	(root node)

		return root; //returning root for every recursive call
}
								
bstNode *listToBst(node *head)
{
		int n = countNodes(head);
														
		return listToBstUtil(&head, n);
}

void preOrder(bstNode *root)
{
    if(!root)
        return;

    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);

}

void printList(node *Node)
{
    while(Node)
    {
        cout << Node -> data << " ";
        Node = Node -> next;
    }

    cout << endl;
}

int main()
{
		node *head = NULL; 
		
		insertNode(&head, 8);
		insertNode(&head, 7); 
		insertNode(&head, 6); 
		insertNode(&head, 5); 
		insertNode(&head, 4); 
		insertNode(&head, 3); 
		insertNode(&head, 2); 
		insertNode(&head, 1);

        printList(head); // 1 2 3 4 5 6 7 8

		bstNode *root = listToBst(head);

		preOrder(root); // 5 3 2 1 4 7 6 8

		return 0; 
}
