#include<iostream>
using namespace std;
struct Node {
	int Data;
	Node *next, *previous;
};
class DoublyLinkedList {
	private:
		Node *head, *tail;
	public:
		DoublyLinkedList() {
			head = NULL;
			tail = NULL;
		}
		DoublyLinkedList(int d) {
			Node *current;
			current->Data = d;
			current->next = 0;
			current->previous = 0;
			if(head==NULL) {
				head = current;
				head->next = NULL;
				head->previous = NULL;
				tail = current;
			}
		}
		//Copy Constructor
		DoublyLinkedList(const DoublyLinkedList& d1) {
			Node *temp = d1.head;
			while(temp != NULL) {
				Node *current;
				current->Data = 0;
				current->next = NULL; current->previous = NULL;
			
				current->Data = temp->Data;
				if(head == NULL) {
					head = current;
					tail = current;
				} 
				else {
					Node *header = head;
					while(header->next != 0)
						header = header->next;
					header->next = current;
					current->previous = header;
					tail = current;
				}
				temp = temp->next;
			}
		}
		
		DoublyLinkedList& operator = (const DoublyLinkedList& rhs) {
			if(this != &rhs) {
				Node *current = rhs->head;
				Node *temp;
				
				while(head != 0) {
					temp  = head;
					head = head->next
					head->previous = 0;
					temp->next = 0;
					temp = 0;
				}
			}
		}
};
