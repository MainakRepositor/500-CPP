/* Program to insert in a sorted list */
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

/* function to insert a new_node
in a list. Note that this
function expects a pointer to
head_ref as this can modify the
head of the input linked list
(similar to push())*/
void sortedInsert(Node** head_ref,
				Node* new_node)
{
	Node* current;
	/* Special case for the head end */
	if (*head_ref == NULL
		|| (*head_ref)->data
			>= new_node->data) {
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else {
		/* Locate the node before the
point of insertion */
		current = *head_ref;
		while (current->next != NULL
&& current->next->data
< new_node->data) {
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}

/* BELOW FUNCTIONS ARE JUST
UTILITY TO TEST sortedInsert */

/* A utility function to
create a new node */
Node* newNode(int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;
	new_node->next = NULL;

	return new_node;
}

/* Function to print linked list */
void printList(Node* head)
{
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

/* Driver program to test count function*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;
	Node* new_node = newNode(5);
	sortedInsert(&head, new_node);
	new_node = newNode(10);
	sortedInsert(&head, new_node);
	new_node = newNode(7);
	sortedInsert(&head, new_node);
	new_node = newNode(3);
	sortedInsert(&head, new_node);
	new_node = newNode(1);
	sortedInsert(&head, new_node);
	new_node = newNode(9);
	sortedInsert(&head, new_node);
	cout << "Created Linked List\n";
	printList(head);

	return 0;
}

