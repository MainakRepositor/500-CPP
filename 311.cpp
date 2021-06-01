// C++ Program to change a BST to Binary Tree
// such that key of a node becomes original
// key plus sum of all greater keys in BST
#include <bits/stdc++.h>
using namespace std;

/* A BST node has key, left child
and right child */
struct node
{
	int key;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node
with the given key and NULL left and right pointers.*/
struct node* newNode(int key)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

// A recursive function that traverses the
// given BST in reverse inorder and for
// every key, adds all greater keys to it
void addGreaterUtil(struct node *root, int *sum_ptr)
{
	// Base Case
	if (root == NULL)
		return;

	// Recur for right subtree first so that sum
	// of all greater nodes is stored at sum_ptr
	addGreaterUtil(root->right, sum_ptr);

	// Update the value at sum_ptr
	*sum_ptr = *sum_ptr + root->key;

	// Update key of this node
	root->key = *sum_ptr;

	// Recur for left subtree so that the
	// updated sum is added to smaller nodes
	addGreaterUtil(root->left, sum_ptr);
}

// A wrapper over addGreaterUtil(). It initializes
// sum and calls addGreaterUtil() to recursively
// update and use value of sum
void addGreater(struct node *root)
{
	int sum = 0;
	addGreaterUtil(root, &sum);
}

// A utility function to print inorder
// traversal of Binary Tree
void printInorder(struct node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->key << " " ;
	printInorder(node->right);
}

// Driver Code
int main()
{
	/* Create following BST
			5
			/ \
		2 13 */
	node *root = newNode(5);
	root->left = newNode(2);
	root->right = newNode(13);

	cout << "Inorder traversal of the "
		<< "given tree" << endl;
	printInorder(root);

	addGreater(root);
	cout << endl;
	cout << "Inorder traversal of the "
		<< "modified tree" << endl;
	printInorder(root);

	return 0;
}

