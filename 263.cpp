// C++ implementation to find leaf
// count of a given Binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left child and
a pointer to right child */
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

/* Function to get the count
of leaf nodes in a binary tree*/
unsigned int getLeafCount(struct node* node)
{
	if(node == NULL)	
		return 0;
	if(node->left == NULL && node->right == NULL)
		return 1;		
	else
		return getLeafCount(node->left)+
			getLeafCount(node->right);
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node = (struct node*)
					malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
return(node);
}

/*Driver code*/
int main()
{
	/*create a tree*/
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
/*get leaf count of the above created tree*/
cout << "Leaf count of the tree is : "<<
				getLeafCount(root) << endl;
return 0;
}

