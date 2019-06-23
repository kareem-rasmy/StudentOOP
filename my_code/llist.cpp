#include <iostream>
#include "llist.h"

using namespace std;

/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
	if (nd->next == nullptr){
		os << nd-> data << " --> nullptr" << endl;
	}
	else {
		os << nd -> data << " --> ";
	}
    return os;
}

/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
	if(curr-> next == nullptr) os << curr <<endl;
	else{
		os << curr;
		print_list(os, curr->next);
	}
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
	if(!head) return nullptr;
    else if (head->next) {
    	last(head -> next);
    }
    else {
    	return head;
    }
}


/*
 * Delete the first node and attach head to the 2nd node:
 * */
bool del_head(Node*& head){
	if (!head) return false;
	else{
		Node* temp = head;
		head = head-> next;
		delete temp;
		return true;
	}
}

/*
 * Delete the last node and set prev->next to nullptr:
 * */
bool del_tail(Node*& curr){
	if (curr->next == nullptr){
		return false;
	}
	else if (curr->next->next){
		del_tail(curr->next);
	}
	else {                                      // if the next node is the last in the list
		delete curr->next;
		curr->next = nullptr;
	}
	return true;
}

/*
 * Duplicate the entire list -- you must not share memory!
 * */
//DOne using a loop


Node* duplicate(Node* head){
	if(head->next == nullptr){
		Node* new_node = new Node(head->data, head->next);
		head->next = new_node;
		return head;
	}
	else{
		duplicate(head->next);
		Node* new_node = new Node(head->data, head->next);
		head->next = new_node;


	}
}


/*
 * Reverse the list: return a brand new list with everything reversed.
 * You could use the add_to_front function  */
Node* reverse(Node* curr, Node* new_next){
	if(curr->next == nullptr){
		add_at_front(new_next, curr->data);
		return new_next;
	}
	else{
		add_at_front(new_next, curr->data);
		reverse(curr->next, new_next);
	}
}

/*
 * Join two lists: tack list 2 onto the end of list 1:
 * Use existing memory.
 * */
Node* join(Node*& list1, Node* list2){
	Node* last_node = last(list1);
	last_node->next = list2;
	return list1;

}



