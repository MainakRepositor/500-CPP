// C++ program to find a triplet
// from three linked lists with
// sum equal to a given number
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
	public:
	int data;
	Node* next;
};

/* A utility function to insert
a node at the beginning of a
linked list*/
void push (Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* A function to check if there are three elements in a, b
and c whose sum is equal to givenNumber. The function
assumes that the list b is sorted in ascending order
and c is sorted in descending order. */
bool isSumSorted(Node *headA, Node *headB,
				Node *headC, int givenNumber)
{
	Node *a = headA;

	// Traverse through all nodes of a
	while (a != NULL)
	{
		Node *b = headB;
		Node *c = headC;

		// For every node of list a, prick two nodes
		// from lists b abd c
		while (b != NULL && c != NULL)
		{
			// If this a triplet with given sum, print
			// it and return true
			int sum = a->data + b->data + c->data;
			if (sum == givenNumber)
			{
			cout << "Triplet Found: " << a->data << " " <<
								b->data << " " << c->data;
			return true;
			}

			// If sum of this triplet is smaller, look for
			// greater values in b
			else if (sum < givenNumber)
				b = b->next;
			else // If sum is greater, look for smaller values in c
				c = c->next;
		}
		a = a->next; // Move ahead in list a
	}

	cout << "No such triplet";
	return false;
}


/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* headA = NULL;
	Node* headB = NULL;
	Node* headC = NULL;

	/*create a linked list 'a' 10->15->5->20 */
	push (&headA, 20);
	push (&headA, 4);
	push (&headA, 15);
	push (&headA, 10);

	/*create a sorted linked list 'b' 2->4->9->10 */
	push (&headB, 10);
	push (&headB, 9);
	push (&headB, 4);
	push (&headB, 2);

	/*create another sorted
	linked list 'c' 8->4->2->1 */
	push (&headC, 1);
	push (&headC, 2);
	push (&headC, 4);
	push (&headC, 8);

	int givenNumber = 25;

	isSumSorted (headA, headB, headC, givenNumber);

	return 0;
}


