// A C++ program to find the deepest left leaf in a given binary tree
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	struct Node *left, *right;
};

Node *newNode(int data)
{
	Node *temp = new Node;
	temp->val = data;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to find deepest leaf node.
// lvl: level of current node.
// maxlvl: pointer to the deepest left leaf node found so far
// isLeft: A bool indicate that this node is left child of its parent
// resPtr: Pointer to the result
void deepestLeftLeafUtil(Node *root, int lvl, int *maxlvl,
						bool isLeft, Node **resPtr)
{
	// Base case
	if (root == NULL)
		return;

	// Update result if this node is left leaf and its level is more
	// than the maxl level of the current result
	if (isLeft && !root->left && !root->right && lvl > *maxlvl)
	{
		*resPtr = root;
		*maxlvl = lvl;
		return;
	}

	// Recur for left and right subtrees
	deepestLeftLeafUtil(root->left, lvl+1, maxlvl, true, resPtr);
	deepestLeftLeafUtil(root->right, lvl+1, maxlvl, false, resPtr);
}

// A wrapper over deepestLeftLeafUtil().
Node* deepestLeftLeaf(Node *root)
{
	int maxlevel = 0;
	Node *result = NULL;
	deepestLeftLeafUtil(root, 0, &maxlevel, false, &result);
	return result;
}

// Driver program to test above function
int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->right->left = newNode(5);
	root->right->right = newNode(6);
	root->right->left->right = newNode(7);
	root->right->right->right = newNode(8);
	root->right->left->right->left = newNode(9);
	root->right->right->right->right = newNode(10);

	Node *result = deepestLeftLeaf(root);
	if (result)
		cout << "The deepest left child is " << result->val;
	else
		cout << "There is no left leaf in the given tree";

	return 0;
}
