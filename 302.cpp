/* A program to construct Binary Tree from preorder traversal */
#include<bits/stdc++.h>

/* A binary tree node structure */
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

/* Utility function to create a new Binary Tree node */
struct node* newNode (int data)
{
	struct node *temp = new struct node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

/* A recursive function to create a Binary Tree from given pre[]
preLN[] arrays. The function returns root of tree. index_ptr is used
to update index values in recursive calls. index must be initially
passed as 0 */
struct node *constructTreeUtil(int pre[], char preLN[], int *index_ptr, int n)
{
	int index = *index_ptr; // store the current value of index in pre[]

	// Base Case: All nodes are constructed
	if (index == n)
		return NULL;

	// Allocate memory for this node and increment index for
	// subsequent recursive calls
	struct node *temp = newNode ( pre[index] );
	(*index_ptr)++;

	// If this is an internal node, construct left and right subtrees and link the subtrees
	if (preLN[index] == 'N')
	{
	temp->left = constructTreeUtil(pre, preLN, index_ptr, n);
	temp->right = constructTreeUtil(pre, preLN, index_ptr, n);
	}

	return temp;
}

// A wrapper over constructTreeUtil()
struct node *constructTree(int pre[], char preLN[], int n)
{
	// Initialize index as 0. Value of index is used in recursion to maintain
	// the current index in pre[] and preLN[] arrays.
	int index = 0;

	return constructTreeUtil (pre, preLN, &index, n);
}


/* This function is used only for testing */
void printInorder (struct node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder (node->left);

	/* then print the data of node */
	printf("%d ", node->data);

	/* now recur on right child */
	printInorder (node->right);
}

/* Driver function to test above functions */
int main()
{
	struct node *root = NULL;

	/* Constructing tree given in the above figure
		10
		/ \
		30 15
	/ \
	20 5 */
	int pre[] = {10, 30, 20, 5, 15};
	char preLN[] = {'N', 'N', 'L', 'L', 'L'};
	int n = sizeof(pre)/sizeof(pre[0]);

	// construct the above tree
	root = constructTree (pre, preLN, n);

	// Test the constructed tree
	printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
	printInorder (root);

	return 0;
}
