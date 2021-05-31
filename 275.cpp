// C++ program to convert binary tree to double tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data,
pointer to left child and a
pointer to right child */
class node
{
	public:
	int data;
	node* left;
	node* right;
};

/* function to create a new
node of tree and returns pointer */
node* newNode(int data);

/* Function to convert a tree to double tree */
void doubleTree(node* Node)
{
	node* oldLeft;
	
	if (Node == NULL) return;
	
	/* do the subtrees */
	doubleTree(Node->left);
	doubleTree(Node->right);
	
	/* duplicate this node to its left */
	oldLeft = Node->left;
	Node->left = newNode(Node->data);
	Node->left->left = oldLeft;
}
	


/* UTILITY FUNCTIONS TO TEST doubleTree() FUNCTION */
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	
	return(Node);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}


/* Driver code*/
int main()
{
	
	/* Constructed binary tree is
				1
			/ \
			2 3
		/ \
		4 5
	*/
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	cout << "Inorder traversal of the original tree is \n";
	printInorder(root);
	
	doubleTree(root);
		
	cout << "\nInorder traversal of the double tree is \n";
	printInorder(root);
	
	return 0;
}


