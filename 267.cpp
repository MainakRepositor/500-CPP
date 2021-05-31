/* C++ Program to convert an aribitary
binary tree to a tree that hold
children sum property */
#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
	
	/* Constructor that allocates a new node
	with the given data and NULL left and right
	pointers. */
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

/* This function is used
to increment left subtree */
void increment(node* node, int diff);

/* This function changes a tree
to hold children sum property */
void convertTree(node* node)
{
	int left_data = 0, right_data = 0, diff;
	
	/* If tree is empty or it's a leaf
		node then return true */
	if (node == NULL || (node->left == NULL &&
						node->right == NULL))
		return;
	else
	{
		/* convert left and right subtrees */
		convertTree(node->left);
		convertTree(node->right);
	
		/* If left child is not present then 0 is used
		as data of left child */
		if (node->left != NULL)
		left_data = node->left->data;
	
		/* If right child is not present then 0 is used
		as data of right child */
		if (node->right != NULL)
		right_data = node->right->data;
	
		/* get the diff of node's data and children sum */
		diff = left_data + right_data - node->data;
	
		/* If node's children sum is
		greater than the node's data */
		if (diff > 0)
		node->data = node->data + diff;
	
		/* THIS IS TRICKY --> If node's data
		is greater than children sum,
		then increment subtree by diff */
		if (diff < 0)
		increment(node, -diff); // -diff is used to make diff positive
	}
}

/* This function is used
to increment subtree by diff */
void increment(node* node, int diff)
{
	/* IF left child is not
	NULL then increment it */
	if(node->left != NULL)
	{
		node->left->data = node->left->data + diff;
	
		// Recursively call to fix
		// the descendants of node->left
		increment(node->left, diff);
	}
	else if (node->right != NULL) // Else increment right child
	{
		node->right->data = node->right->data + diff;
	
		// Recursively call to fix
		// the descendants of node->right
		increment(node->right, diff);
	}
}

/* Given a binary tree,
printInorder() prints out its
inorder traversal*/
void printInorder(node* node)
{
	if (node == NULL)
		return;
	
	/* first recur on left child */
	printInorder(node->left);
	
	/* then print the data of node */
	cout<<node->data<<" ";
	
	/* now recur on right child */
	printInorder(node->right);
}

/* Driver code */
int main()
{
	node *root = new node(50);
	root->left = new node(7);
	root->right = new node(2);
	root->left->left = new node(3);
	root->left->right = new node(5);
	root->right->left = new node(1);
	root->right->right = new node(30);
	
	cout << "\nInorder traversal before conversion: " << endl;
	printInorder(root);
	
	convertTree(root);
	
	cout << "\nInorder traversal after conversion: " << endl;
	printInorder(root);
	return 0;
}
