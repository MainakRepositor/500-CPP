// CPP program to find maximum sum leaf to root
// path in Binary Tree
#include <bits/stdc++.h>
using namespace std;

/* A tree node structure */
class node {
public:
	int data;
	node* left;
	node* right;
};

// A utility function that prints all nodes
// on the path from root to target_leaf
bool printPath(node* root,
			node* target_leaf)
{
	// base case
	if (root == NULL)
		return false;

	// return true if this node is the target_leaf
	// or target leaf is present in one of its
	// descendants
	if (root == target_leaf || printPath(root->left, target_leaf) ||
							printPath(root->right, target_leaf)) {
		cout << root->data << " ";
		return true;
	}

	return false;
}

// This function Sets the target_leaf_ref to refer
// the leaf node of the maximum path sum. Also,
// returns the max_sum using max_sum_ref
void getTargetLeaf(node* Node, int* max_sum_ref,
				int curr_sum, node** target_leaf_ref)
{
	if (Node == NULL)
		return;

	// Update current sum to hold sum of nodes on path
	// from root to this node
	curr_sum = curr_sum + Node->data;

	// If this is a leaf node and path to this node has
	// maximum sum so far, then make this node target_leaf
	if (Node->left == NULL && Node->right == NULL) {
		if (curr_sum > *max_sum_ref) {
			*max_sum_ref = curr_sum;
			*target_leaf_ref = Node;
		}
	}

	// If this is not a leaf node, then recur down
	// to find the target_leaf
	getTargetLeaf(Node->left, max_sum_ref, curr_sum,
				target_leaf_ref);
	getTargetLeaf(Node->right, max_sum_ref, curr_sum,
				target_leaf_ref);
}

// Returns the maximum sum and prints the nodes on max
// sum path
int maxSumPath(node* Node)
{
	// base case
	if (Node == NULL)
		return 0;

	node* target_leaf;
	int max_sum = INT_MIN;

	// find the target leaf and maximum sum
	getTargetLeaf(Node, &max_sum, 0, &target_leaf);

	// print the path from root to the target leaf
	printPath(Node, target_leaf);

	return max_sum; // return maximum sum
}

/* Utility function to create a new Binary Tree node */
node* newNode(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

/* Driver function to test above functions */
int main()
{
	node* root = NULL;

	/* Constructing tree given in the above figure */
	root = newNode(10);
	root->left = newNode(-2);
	root->right = newNode(7);
	root->left->left = newNode(8);
	root->left->right = newNode(-4);

	cout << "Following are the nodes on the maximum "
			"sum path \n";
	int sum = maxSumPath(root);
	cout << "\nSum of the nodes is " << sum;
	return 0;
}


