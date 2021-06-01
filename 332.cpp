// CPP program to find
// difference between
// sums of odd level
// and even level nodes
// of binary tree
#include <bits/stdc++.h>
using namespace std;

// tree node
struct Node
{
	int data;
	Node *left, *right;
};

// returns a new
// tree Node
Node* newNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// return difference of
// sums of odd level
// and even level
int evenOddLevelDifference(Node* root)
{
	if (!root)
		return 0;

	// create a queue for
	// level order traversal
	queue<Node*> q;
	q.push(root);

	int level = 0;
	int evenSum = 0, oddSum = 0;

	// traverse until the
	// queue is empty
	while (!q.empty())
	{
		int size = q.size();
		level += 1;

		// traverse for
		// complete level
		while(size > 0)
		{
			Node* temp = q.front();
			q.pop();

			// check if level no.
			// is even or odd and
			// accordingly update
			// the evenSum or oddSum
			if(level % 2 == 0)
				evenSum += temp->data;
			else
				oddSum += temp->data;
		
			// check for left child
			if (temp->left)
			{
				q.push(temp->left);
			}
			
			// check for right child
			if (temp->right)
			{
				q.push(temp->right);
			}
			size -= 1;
		}
	}
	
	return (oddSum - evenSum);
}

// driver program
int main()
{
	// construct a tree
	Node* root = newNode(5);
	root->left = newNode(2);
	root->right = newNode(6);
	root->left->left = newNode(1);
	root->left->right = newNode(4);
	root->left->right->left = newNode(3);
	root->right->right = newNode(8);
	root->right->right->right = newNode(9);
	root->right->right->left = newNode(7);

	int result = evenOddLevelDifference(root);
	cout << "diffence between sums is :: ";
	cout << result << endl;
	return 0;
}


