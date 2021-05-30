/* This program swaps the nodes of
linked list rather than swapping the
field from the nodes.
Imagine a case where a node contains
many fields, there will be plenty
of unnecessary swap calls. */

#include <bits/stdc++.h>
using namespace std;

/* A linked list node */
class node {
public:
	int data;
	node* next;
};

/* Function to pairwise swap elements
of a linked list. It returns head of
the modified list, so return value
of this node must be assigned */
node* pairWiseSwap(node* head)
{
	// If linked list is empty or
	// there is only one node in list
	if (head == NULL || head->next == NULL)
		return head;

	// Initialize previous and current pointers
	node* prev = head;
	node* curr = head->next;

	head = curr; // Change head before proceeding

	// Traverse the list
	while (true) {
		node* next = curr->next;
		curr->next = prev; // Change next of
		// current as previous node

		// If next NULL or next is the last node
		if (next == NULL || next->next == NULL) {
			prev->next = next;
			break;
		}

		// Change next of previous to next of next
		prev->next = next->next;

		// Update previous and curr
		prev = next;
		curr = prev->next;
	}
	return head;
}

/* Function to add a node at
the beginning of Linked List */
void push(node** head_ref, int new_data)
{
	/* allocate node */
	node* new_node = new node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes
in a given linked list */
void printList(node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

/* Driver code */
int main()
{
	node* start = NULL;

	/* The constructed linked list is:
	1->2->3->4->5->6->7 */
	push(&start, 7);
	push(&start, 6);
	push(&start, 5);
	push(&start, 4);
	push(&start, 3);
	push(&start, 2);
	push(&start, 1);

	cout << "Linked list before "
	<< "calling pairWiseSwap() ";
	printList(start);

	start = pairWiseSwap(start); // NOTE THIS CHANGE

	cout << "\nLinked list after calling"
	<< "pairWiseSwap() ";
	printList(start);

	return 0;
}
