// Iterative CPP program to connect
// nodes at same level using
// constant extra space
#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
	node *nextRight;
	
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

/* This function returns the leftmost
child of nodes at the same level as p.
This function is used to getNExt right
of p's right child If right child of
is NULL then this can also be used for
the left child */
node *getNextRight(node *p)
{
	node *temp = p->nextRight;

	/* Traverse nodes at p's level
	and find and return the first
	node's first child */
	while (temp != NULL)
	{
		if (temp->left != NULL)
			return temp->left;
		if (temp->right != NULL)
			return temp->right;
		temp = temp->nextRight;
	}

	// If all the nodes at p's level
	// are leaf nodes then return NULL
	return NULL;
}

/* Sets nextRight of all nodes
of a tree with root as p */
void connectRecur(node* p)
{
	node *temp;

	if (!p)
	return;

	// Set nextRight for root
	p->nextRight = NULL;

	// set nextRight of all levels one by one
	while (p != NULL)
	{
		node *q = p;

		/* Connect all childrem nodes of p and
		children nodes of all other nodes at
		same level as p */
		while (q != NULL)
		{
			// Set the nextRight pointer
			// for p's left child
			if (q->left)
			{
				// If q has right child, then
				// right child is nextRight of
				// p and we also need to set
				// nextRight of right child
				if (q->right)
					q->left->nextRight = q->right;
				else
					q->left->nextRight = getNextRight(q);
			}

			if (q->right)
				q->right->nextRight = getNextRight(q);

			// Set nextRight for other
			// nodes in pre order fashion
			q = q->nextRight;
		}

		// start from the first
		// node of next level
		if (p->left)
			p = p->left;
		else if (p->right)
			p = p->right;
		else
			p = getNextRight(p);
	}
}


/* Driver code*/
int main()
{

	/* Constructed binary tree is
			10
			/ \
		8 2
		/	 \
	3	 90
	*/
	node *root = new node(10);
	root->left = new node(8);
	root->right = new node(2);
	root->left->left = new node(3);
	root->right->right	 = new node(90);

	// Populates nextRight pointer in all nodes
	connectRecur(root);

	// Let us check the values of nextRight pointers
	cout << "Following are populated nextRight pointers in the tree"
		" (-1 is printed if there is no nextRight) \n";
	cout << "nextRight of " << root->data << " is "
		<< (root->nextRight? root->nextRight->data: -1) <<endl;
	cout << "nextRight of " << root->left->data << " is "
		<< (root->left->nextRight? root->left->nextRight->data: -1) << endl;
	cout << "nextRight of " << root->right->data << " is "
		<< (root->right->nextRight? root->right->nextRight->data: -1) << endl;
	cout << "nextRight of " << root->left->left->data<< " is "
		<< (root->left->left->nextRight? root->left->left->nextRight->data: -1) << endl;
	cout << "nextRight of " << root->right->right->data << " is "
		<< (root->right->right->nextRight? root->right->right->nextRight->data: -1) << endl;
	return 0;
}


