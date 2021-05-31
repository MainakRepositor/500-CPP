// Program to find ceil of a given value in BST
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has key, left child and right child */
class node {
public:
	int key;
	node* left;
	node* right;
};

/* Helper function that allocates a new node with the given key and
NULL left and right pointers.*/
node* newNode(int key)
{
	node* Node = new node();
	Node->key = key;
	Node->left = NULL;
	Node->right = NULL;
	return (Node);
}

// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1
int Ceil(node* root, int input)
{
	// Base case
	if (root == NULL)
		return -1;

	// We found equal key
	if (root->key == input)
		return root->key;

	// If root's key is smaller, ceil must be in right subtree
	if (root->key < input)
		return Ceil(root->right, input);

	// Else, either left subtree or root has the ceil value
	int ceil = Ceil(root->left, input);
	return (ceil >= input) ? ceil : root->key;
}

// Driver program to test above function
int main()
{
	node* root = newNode(8);

	root->left = newNode(4);
	root->right = newNode(12);

	root->left->left = newNode(2);
	root->left->right = newNode(6);

	root->right->left = newNode(10);
	root->right->right = newNode(14);

	for (int i = 0; i < 16; i++)
		cout << i << " " << Ceil(root, i) << endl;

	return 0;
}

