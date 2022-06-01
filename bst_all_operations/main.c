#include "bst_util.h"
int main(void)
{
		struct bst_node *root=NULL; 
		root=insert(root, 30); 
		root=insert(root, 10); 
		root=insert(root, 50);
        root=insert(root, 5);
        root=insert(root, 15);
        root=insert(root, 40);
        root=insert(root, 80);
        root=delete(root, 80);
        root=delete(root, 50);
        root=delete(root, 10);
        //pre_order(root);
       // post_order(root);
     //   printf("%d", height(root));
        //level_order(root);
		in_order(root); 
        struct bst_node *temp;
        if((temp = search_node(root, 1034)))
            printf("%d", temp->data);
        else
            exit(0);
		


}

