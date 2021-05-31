/* program for construction of full binary tree */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
	public:
	int data;
	node *left;
	node *right;
};

// A utility function to create a node
node* newNode (int data)
{
	node* temp = new node();

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

// A recursive function to construct Full from pre[] and post[].
// preIndex is used to keep track of index in pre[].
// l is low index and h is high index for the current subarray in post[]
node* constructTreeUtil (int pre[], int post[], int* preIndex,
								int l, int h, int size)
{
	// Base case
	if (*preIndex >= size || l > h)
		return NULL;

	// The first node in preorder traversal is root. So take the node at
	// preIndex from preorder and make it root, and increment preIndex
	node* root = newNode ( pre[*preIndex] );
	++*preIndex;

	// If the current subarry has only one element, no need to recur
	if (l == h)
		return root;

	// Search the next element of pre[] in post[]
	int i;
	for (i = l; i <= h; ++i)
		if (pre[*preIndex] == post[i])
			break;

	// Use the index of element found in postorder to divide
		// postorder array in two parts. Left subtree and right subtree
	if (i <= h)
	{
		root->left = constructTreeUtil (pre, post, preIndex,
												l, i, size);
		root->right = constructTreeUtil (pre, post, preIndex,
												i + 1, h, size);
	}

	return root;
}

// The main function to construct Full Binary Tree from given preorder and
// postorder traversals. This function mainly uses constructTreeUtil()
node *constructTree (int pre[], int post[], int size)
{
	int preIndex = 0;
	return constructTreeUtil (pre, post, &preIndex, 0, size - 1, size);
}

// A utility function to print inorder traversal of a Binary Tree
void printInorder (node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main ()
{
	int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
	int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
	int size = sizeof( pre ) / sizeof( pre[0] );

	node *root = constructTree(pre, post, size);

	cout<<"Inorder traversal of the constructed tree: \n";
	printInorder(root);

	return 0;
}

