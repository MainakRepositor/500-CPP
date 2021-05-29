#include <bits/stdc++.h>
using namespace std;

/* A linked list node */
class Node
{
	public:
	int data;
	Node *next;
};


/* Prints a linked list in reverse manner */
void fun1(Node* head)
{
	if(head == NULL)
		return;
	
	fun1(head->next);
	cout << head->data << " ";
}

/* prints alternate nodes of a Linked List, first
from head to end, and then from end to head. */
void fun2(Node* start)
{
	if(start == NULL)
		return;
	cout<<start->data<<" ";
	
	if(start->next != NULL )
		fun2(start->next->next);
	cout << start->data << " ";
}

/* UTILITY FUNCTIONS TO TEST fun1() and fun2() */
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

/* Driver code */
int main()
{
	/* Start with the empty list */
	Node* head = NULL;
	
	/* Using push() to construct below list
		1->2->3->4->5 */
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	
	cout<<"Output of fun1() for list 1->2->3->4->5 \n";
	fun1(head);
	
	cout<<"\nOutput of fun2() for list 1->2->3->4->5 \n";
	fun2(head);

	return 0;
}


