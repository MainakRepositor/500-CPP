#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

/* Given a reference (pointer to pointer) to the head
	of a list and an int, push a new node on the front
	of the list. */
void push(Node** head_ref, int new_data)
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

void printList(Node* head)
{
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void deleteNode(Node* node)
{
	Node* prev;
	if (node == NULL)
		return;
	else {
		while (node->next != NULL) {
			node->data = node->next->data;
			prev = node;
			node = node->next;
		}
		prev->next = NULL;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	/* Use push() to construct below list
	1->12->1->4->1 */
	push(&head, 1);
	push(&head, 4);
	push(&head, 1);
	push(&head, 12);
	push(&head, 1);

	cout << "Before deleting \n";
	printList(head);

	/* I m deleting the head itself.
		You can check for more cases */
	deleteNode(head);

	cout << "\nAfter deleting \n";
	printList(head);
	return 0;
}


