#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
	if (!nd) os << nd-> data << " --> nullptr";
	else os << nd -> data << " --> ";
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
	if(head) add_at_end(head ->next , d);
	else {
		Node* new_node = new Node(d);
		head = new_node;
	}
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
	if(curr) os << curr;
	else os << curr;
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
	Node* new_node = new Node(d);
	new_node->next = head;
	head = new_node;
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {

	if(head->next) {last(head -> next);}
	else{
		return head;
	}

}
