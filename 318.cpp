#include <bits/stdc++.h>
using namespace std;

// A tree node
struct Node {

	int data;
	Node *left, *right;
};

// Function to create a new node with the given data
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}
// An iterative function to do post order
// traversal of a given binary tree
void postOrderIterative(Node* root)
{
	if (root == NULL)
		return;

	// Create two stacks
	stack<Node *> s1, s2;

	// push root to first stack
	s1.push(root);
	Node* node;

	// Run while first stack is not empty
	while (!s1.empty()) {
		// Pop an item from s1 and push it to s2
		node = s1.top();
		s1.pop();
		s2.push(node);

		// Push left and right children
		// of removed item to s1
		if (node->left)
			s1.push(node->left);
		if (node->right)
			s1.push(node->right);
	}

	// Print all elements of second stack
	while (!s2.empty()) {
		node = s2.top();
		s2.pop();
		cout << node->data << " ";
	}
}

// Driver code
int main()
{
	// Let us construct the tree
	// shown in above figure
	Node* root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	postOrderIterative(root);

	return 0;
}
