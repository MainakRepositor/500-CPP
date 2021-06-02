// C++ program to extract leaves of
// a Binary Tree in a Doubly Linked List
#include <bits/stdc++.h>
using namespace std;

// Structure for tree and linked list
class Node
{
	public:
	int data;
	Node *left, *right;
};

// Main function which extracts all
// leaves from given Binary Tree.
// The function returns new root of
// Binary Tree (Note that root may change
// if Binary Tree has only one node).
// The function also sets *head_ref as
// head of doubly linked list. left pointer
// of tree is used as prev in DLL
// and right pointer is used as next
Node* extractLeafList(Node *root, Node **head_ref)
{
// Base cases
if (root == NULL) return NULL;

if (root->left == NULL && root->right == NULL)
{
	// This node is going to be added
	// to doubly linked list of leaves,
	// set right pointer of this node
	// as previous head of DLL. We
	// don't need to set left pointer
	// as left is already NULL
	root->right = *head_ref;

	// Change left pointer of previous head
	if (*head_ref != NULL) (*head_ref)->left = root;

	// Change head of linked list
	*head_ref = root;

	return NULL; // Return new root
}

// Recur for right and left subtrees
root->right = extractLeafList(root->right, head_ref);
root->left = extractLeafList(root->left, head_ref);

return root;
}

// Utility function for allocating node for Binary Tree.
Node* newNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// Utility function for printing tree in In-Order.
void print(Node *root)
{
	if (root != NULL)
	{
		print(root->left);
		cout<<root->data<<" ";
		print(root->right);
	}
}

// Utility function for printing double linked list.
void printList(Node *head)
{
	while (head)
	{
		cout<<head->data<<" ";
		head = head->right;
	}
}

// Driver code
int main()
{
	Node *head = NULL;
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);
	root->left->left->left = newNode(7);
	root->left->left->right = newNode(8);
	root->right->right->left = newNode(9);
	root->right->right->right = newNode(10);

	cout << "Inorder Trvaersal of given Tree is:\n";
	print(root);

	root = extractLeafList(root, &head);

	cout << "\nExtracted Double Linked list is:\n";
	printList(head);

	cout << "\nInorder traversal of modified tree is:\n";
	print(root);
	return 0;
}


