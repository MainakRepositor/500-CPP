/* In a balanced binary search tree
isPairPresent two element which sums to
a given value time O(n) space O(logn) */
#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100

// A BST node
class node {
public:
	int val;
	node *left, *right;
};

// Stack type
class Stack {
public:
	int size;
	int top;
	node** array;
};

// A utility function to create a stack of given size
Stack* createStack(int size)
{
	Stack* stack = new Stack();
	stack->size = size;
	stack->top = -1;
	stack->array = new node*[(stack->size * sizeof(node*))];
	return stack;
}

// BASIC OPERATIONS OF STACK
int isFull(Stack* stack)
{
	return stack->top - 1 == stack->size;
}

int isEmpty(Stack* stack)
{
	return stack->top == -1;
}

void push(Stack* stack, node* node)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = node;
}

node* pop(Stack* stack)
{
	if (isEmpty(stack))
		return NULL;
	return stack->array[stack->top--];
}

// Returns true if a pair with target
// sum exists in BST, otherwise false
bool isPairPresent(node* root, int target)
{
	// Create two stacks. s1 is used for
	// normal inorder traversal and s2 is
	// used for reverse inorder traversal
	Stack* s1 = createStack(MAX_SIZE);
	Stack* s2 = createStack(MAX_SIZE);

	// Note the sizes of stacks is MAX_SIZE,
	// we can find the tree size and fix stack size
	// as O(Logn) for balanced trees like AVL and Red Black
	// tree. We have used MAX_SIZE to keep the code simple

	// done1, val1 and curr1 are used for
	// normal inorder traversal using s1
	// done2, val2 and curr2 are used for
	// reverse inorder traversal using s2
	bool done1 = false, done2 = false;
	int val1 = 0, val2 = 0;
	node *curr1 = root, *curr2 = root;

	// The loop will break when we either find a pair or one of the two
	// traversals is complete
	while (1) {
		// Find next node in normal Inorder
		// traversal. See following post
		// https:// www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
		while (done1 == false) {
			if (curr1 != NULL) {
				push(s1, curr1);
				curr1 = curr1->left;
			}
			else {
				if (isEmpty(s1))
					done1 = 1;
				else {
					curr1 = pop(s1);
					val1 = curr1->val;
					curr1 = curr1->right;
					done1 = 1;
				}
			}
		}

		// Find next node in REVERSE Inorder traversal. The only
		// difference between above and below loop is, in below loop
		// right subtree is traversed before left subtree
		while (done2 == false) {
			if (curr2 != NULL) {
				push(s2, curr2);
				curr2 = curr2->right;
			}
			else {
				if (isEmpty(s2))
					done2 = 1;
				else {
					curr2 = pop(s2);
					val2 = curr2->val;
					curr2 = curr2->left;
					done2 = 1;
				}
			}
		}

		// If we find a pair, then print the pair and return. The first
		// condition makes sure that two same values are not added
		if ((val1 != val2) && (val1 + val2) == target) {
			cout << "Pair Found: " << val1 << "+ " << val2 << " = " << target << endl;
			return true;
		}

		// If sum of current values is smaller,
		// then move to next node in
		// normal inorder traversal
		else if ((val1 + val2) < target)
			done1 = false;

		// If sum of current values is greater,
		// then move to next node in
		// reverse inorder traversal
		else if ((val1 + val2) > target)
			done2 = false;

		// If any of the inorder traversals is
		// over, then there is no pair
		// so return false
		if (val1 >= val2)
			return false;
	}
}

// A utility function to create BST node
node* NewNode(int val)
{
	node* tmp = new node();
	tmp->val = val;
	tmp->right = tmp->left = NULL;
	return tmp;
}

// Driver program to test above functions
int main()
{
	/*
				15
				/ \
			10 20
			/ \ / \
			8 12 16 25 */
	node* root = NewNode(15);
	root->left = NewNode(10);
	root->right = NewNode(20);
	root->left->left = NewNode(8);
	root->left->right = NewNode(12);
	root->right->left = NewNode(16);
	root->right->right = NewNode(25);

	int target = 33;
	if (isPairPresent(root, target) == false)
		cout << "\nNo such values are found\n";
	return 0;
}


