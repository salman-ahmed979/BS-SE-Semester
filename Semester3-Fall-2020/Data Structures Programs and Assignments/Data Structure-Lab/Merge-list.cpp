#include<iostream>
using namespace std;
struct Node {
	int data;
	Node *next;
};
class SinglyLinkedList {
	private:
		Node *head;
	public:
		SinglyLinkedList() {
			head = 0;
		}
		void AddNodeAtEnd(int data) {
			Node *temp = new Node;
			temp->data = data;
			temp->next = 0;
			Node *current = head;
			if(head == 0) {
				head = temp;
				head->next = 0;
			}
			else
			{
				while(current->next != 0)
					current = current->next;
				current->next = temp;
				current = temp;
				current->next = 0;
			}
		}
		Node* Merge_LinkedList(SinglyLinkedList &obj1, SinglyLinkedList &obj2) {
			Node *l1 = obj1.head; Node *l2 = obj2.head;
			Node *temp = new Node;
			Node *header = temp;
			if(l1 != 0 && l2 !=0) {
				if(l1->data <= l2->data) {
					temp->data = l1->data;
					temp->next = 0;
					header = temp;
					l1 = l1->next;
				}
				else
				{
					temp->data = l1->data;
					temp->next = 0;
					header = temp;
					l2 = l2->next;
				}
			}
			while(l1 != 0 && temp!=0) {
				if(l1->data <= l2->data && l2 != 0) {
					Node *temper = new Node;
					temper->data = l1->data;
					temper->next = 0;
					temp->next = temper;
					temp = temper;
					l1 = l1->next;
				}
				else if(l2 != 0)
				{
					Node *temper = new Node;
					temper->data = l2->data;
					temper->next = 0;
					temp->next = temper;
					temp = temper;
					l2 = l2->next;
				}
				else {
					Node *temper = new Node;
					temper->data = l1->data;
					temper->next = 0;
					temp->next = temper;
					temp = temper;
					l1 = l1->next;
				}
			}
			while(l2 != 0 && temp!=0) {
					Node *temper = new Node;
					temper->data = l2->data;
					temper->next = 0;
					temp->next = temper;
					temp = temper;
					l2 = l2->next;
			}
			return header;
		}
};
void print(Node *header) {
	Node *current = header;
	while(current != 0) {
		cout << current->data << " ";
		current = current->next;
	} 
}
int main() {
	SinglyLinkedList s1, s2, s3;
	for(int i=0; i<4; i++)
		s1.AddNodeAtEnd(i);
	for(int i=2; i<8; i++)
		s2.AddNodeAtEnd(i);
	Node *ptr = s3.Merge_LinkedList(s1,s2);
	print(ptr);
	return 0;
}
