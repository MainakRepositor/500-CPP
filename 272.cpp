#include <bits/stdc++.h>
using namespace std;
#define bool int

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
	public:
	int data;
	node* left;
	node* right;
};

/*
Given a tree and a sum, return true if there is a path from the root
down to a leaf, such that adding up all the values along the path
equals the given sum.

Strategy: subtract the node value from the sum when recurring down,
and check to see if the sum is 0 when you run out of tree.
*/
bool hasPathSum(node* Node, int sum)
{
	/* return true if we run out of tree and sum==0 */
	if (Node == NULL)
	{
		return (sum == 0);
	}
	
	else
	{
		bool ans = 0;
	
		int subSum = sum - Node->data;
	
		/* If we reach a leaf node and sum becomes 0 then return true*/
		if ( subSum == 0 && Node->left == NULL && Node->right == NULL )
		return 1;
		
		/* otherwise check both subtrees */
		if(Node->left)
			ans = ans || hasPathSum(Node->left, subSum);
		if(Node->right)
			ans = ans || hasPathSum(Node->right, subSum);
	
		return ans;
	}
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newnode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;
	
	return(Node);
}

// Driver Code
int main()
{

	int sum = 21;
	
	/* Constructed binary tree is
				10
			/ \
			8 2
		/ \ /
		3 5 2
	*/
	node *root = newnode(10);
	root->left = newnode(8);
	root->right = newnode(2);
	root->left->left = newnode(3);
	root->left->right = newnode(5);
	root->right->left = newnode(2);
	
	if(hasPathSum(root, sum))
		cout << "There is a root-to-leaf path with sum " << sum;
	else
		cout << "There is no root-to-leaf path with sum " << sum;
	
	return 0;
}

