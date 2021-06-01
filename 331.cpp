// C++ program to print all ancestors of a given key
#include <bits/stdc++.h>
using namespace std;


// Structure for a tree node
struct Node
{
	int data;
	struct Node *left, *right;
};

// A utility function to create a new tree node
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// Iterative Function to print all ancestors of a given key
void printAncestors(struct Node *root, int key)
{
	if (root == NULL) return;

	// Create a stack to hold ancestors
	stack<struct Node* > st;

	// Traverse the complete tree in postorder way till we find the key
	while (1)
	{
		// Traverse the left side. While traversing, push the nodes into
		// the stack so that their right subtrees can be traversed later
		while (root && root->data != key)
		{
			st.push(root); // push current node
			root = root->left; // move to next node
		}

		// If the node whose ancestors are to be printed is found,
		// then break the while loop.
		if (root && root->data == key)
			break;

		// Check if right sub-tree exists for the node at top
		// If not then pop that node because we don't need this
		// node any more.
		if (st.top()->right == NULL)
		{
			root = st.top();
			st.pop();

			// If the popped node is right child of top, then remove the top
			// as well. Left child of the top must have processed before.

			while (!st.empty() && st.top()->right == root)
			{root = st.top();
			st.pop();
			}
		}

		// if stack is not empty then simply set the root as right child
		// of top and start traversing right sub-tree.
		root = st.empty()? NULL: st.top()->right;
	}

	// If stack is not empty, print contents of stack
	// Here assumption is that the key is there in tree
	while (!st.empty())
	{
		cout<<st.top()->data<<" ";
		st.pop();
	}
}

// Driver program to test above functions
int main()
{
	// Let us construct a binary tree
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left->left = newNode(8);
	root->left->right->right = newNode(9);
	root->right->right->left = newNode(10);

	cout<<"Following are all keys and their ancestors"<<endl;
	for (int key = 1; key <= 10; key++)
	{
		cout<<key<<":"<<" ";
		printAncestors(root, key);
		cout<<endl;
	}

	return 0;
}

