// C++ program to find depth of the
// deepest odd level leaf node
#include <bits/stdc++.h>
using namespace std;

// A utility function to find
// maximum of two integers
int max(int x, int y)
{
	return (x > y)? x : y;
}

// A Binary Tree node
struct Node
{
	int data;
	struct Node *left, *right;
};

// A utility function to allocate a
// new tree node
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// A recursive function to find depth of
// the deepest odd level leaf
int depthOfOddLeafUtil(struct Node *root,
							int level)
{
	// Base Case
	if (root == NULL)
		return 0;

	// If this node is a leaf and its level
	// is odd, return its level
	if (root->left == NULL &&
		root->right == NULL && level & 1)
		return level;

	// If not leaf, return the maximum value
	// from left and right subtrees
	return max(depthOfOddLeafUtil(root->left, level + 1),
			depthOfOddLeafUtil(root->right, level + 1));
}

/* Main function which calculates the depth
of deepest odd level leaf. This function
mainly uses depthOfOddLeafUtil() */
int depthOfOddLeaf(struct Node *root)
{
	int level = 1, depth = 0;
	return depthOfOddLeafUtil(root, level);
}

// Driver Code
int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->right->left = newNode(5);
	root->right->right = newNode(6);
	root->right->left->right = newNode(7);
	root->right->right->right = newNode(8);
	root->right->left->right->left = newNode(9);
	root->right->right->right->right = newNode(10);
	root->right->right->right->right->left = newNode(11);

	cout << depthOfOddLeaf(root)
		<< " is the required depth";
	getchar();
	return 0;
}


