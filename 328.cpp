/* Program to find height of the tree by Iterative Method */
#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct node
{
	struct node *left;
	int data;
	struct node *right;
};

// Iterative method to find the height of Binary Tree
int treeHeight(node *root)
{
	// Base Case
	if (root == NULL)
		return 0;

	// Create an empty queue for level order tarversal
	queue<node *> q;

	// Enqueue Root and initialize height
	q.push(root);
	int height = 0;

	while (1)
	{
		// nodeCount (queue size) indicates number of nodes
		// at current lelvel.
		int nodeCount = q.size();
		if (nodeCount == 0)
			return height;

		height++;

		// Dequeue all nodes of current level and Enqueue all
		// nodes of next level
		while (nodeCount > 0)
		{
			node *node = q.front();
			q.pop();
			if (node->left != NULL)
				q.push(node->left);
			if (node->right != NULL)
				q.push(node->right);
			nodeCount--;
		}
	}
}

// Utility function to create a new tree node
node* newNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree shown in above diagram
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Height of tree is " << treeHeight(root);
	return 0;
}
