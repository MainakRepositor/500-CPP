// A simple inorder traversal based C++ program
// to find k-th smallest element in a BST.
#include <iostream>
using namespace std;

// A BST node
struct Node {
	int data;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

// Recursive function to insert an key into BST
Node* insert(Node* root, int x)
{
	if (root == NULL)
		return new Node(x);
	if (x < root->data)
		root->left = insert(root->left, x);
	else if (x > root->data)
		root->right = insert(root->right, x);
	return root;
}

// Function to find k'th largest element in BST
// Here count denotes the number of nodes processed so far
Node* kthSmallest(Node* root, int& k)
{
	// base case
	if (root == NULL)
		return NULL;

	// search in left subtree
	Node* left = kthSmallest(root->left, k);

	// if k'th smallest is found in left subtree, return it
	if (left != NULL)
		return left;

	// if current element is k'th smallest, return it
	k--;
	if (k == 0)
		return root;

	// else search in right subtree
	return kthSmallest(root->right, k);
}

// Function to find k'th largest element in BST
void printKthSmallest(Node* root, int k)
{
	// maintain index to count number of nodes processed so far
	int count = 0;
	Node* res = kthSmallest(root, k);
	if (res == NULL)
		cout << "There are less than k nodes in the BST";
	else
		cout << "K-th Smallest Element is " << res->data;
}

// main function
int main()
{
	Node* root = NULL;
	int keys[] = { 20, 8, 22, 4, 12, 10, 14 };

	for (int x : keys)
		root = insert(root, x);

	int k = 3;
	printKthSmallest(root, k);
	return 0;
}
