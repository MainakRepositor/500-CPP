// CPP program to connect nodes
// at same level using extended
// pre-order traversal
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node* nextRight;

	/* Constructor that allocates a new node with the
	given data and NULL left and right pointers. */
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->nextRight = NULL;
	}
};

void connectRecur(node* p);

// Sets the nextRight of
// root and calls connectRecur()
// for other nodes
void connect(node* p)
{
	// Set the nextRight for root
	p->nextRight = NULL;

	// Set the next right for rest of the nodes
	// (other than root)
	connectRecur(p);
}

/* Set next right of all descendents of p.
Assumption: p is a compete binary tree */
void connectRecur(node* p)
{
	// Base case
	if (!p)
		return;

	// Set the nextRight pointer for p's left child
	if (p->left)
		p->left->nextRight = p->right;

	// Set the nextRight pointer
	// for p's right child p->nextRight
	// will be NULL if p is the right
	// most child at its level
	if (p->right)
		p->right->nextRight = (p->nextRight) ? p->nextRight->left : NULL;

	// Set nextRight for other
	// nodes in pre order fashion
	connectRecur(p->left);
	connectRecur(p->right);
}

/* Driver code*/
int main()
{

	/* Constructed binary tree is
				10
			/ \
			8 2
		/
		3
	*/
	node* root = new node(10);
	root->left = new node(8);
	root->right = new node(2);
	root->left->left = new node(3);

	// Populates nextRight pointer in all nodes
	connect(root);

	// Let us check the values
	// of nextRight pointers
	cout << "Following are populated nextRight pointers in the tree"
			" (-1 is printed if there is no nextRight)\n";
	cout << "nextRight of " << root->data << " is "
		<< (root->nextRight ? root->nextRight->data : -1) << endl;
	cout << "nextRight of " << root->left->data << " is "
		<< (root->left->nextRight ? root->left->nextRight->data : -1) << endl;
	cout << "nextRight of " << root->right->data << " is "
		<< (root->right->nextRight ? root->right->nextRight->data : -1) << endl;
	cout << "nextRight of " << root->left->left->data << " is "
		<< (root->left->left->nextRight ? root->left->left->nextRight->data : -1) << endl;
	return 0;
}


