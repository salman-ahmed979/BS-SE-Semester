#include<iostream>
using namespace std;
struct Node {
	int Data;
	Node *next;
};
class SinglyLinkedlist {
	private:
		Node *head;
	public:
		SinglyLinkedlist()
		{
			head = 0;
		}
		SinglyLinkedlist(int data) {
			Node *temp = new Node;
			temp->Data = data;
			temp->next = NULL;
			head = temp;
			//head->next = 0;
			temp = 0;
		}
		//Copy Constructor
		SinglyLinkedlist (const SinglyLinkedlist& rhs) {
			Node *current = rhs.head;
			this->head = 0;
			Node *last = head;
			while(current!=0)
			{
				Node *temp = new Node;
				temp->Data = current->Data;
				temp->next = 0;
				if(head == 0)
				{
					head = temp;
					head->next = 0;
					last = head;
				}
				else {
					last->next = temp;
					last = temp;	
				}
				current = current->next;
			}
		}
		//Insert Data at front of Node
		void InsertAtFront(int data) {
			Node *temp = new Node;
			temp->Data = data;
			if(head==0)
				head = temp;
			else {
				temp->next = head;
				head = temp;
			}
		}
		//Insert Data at back of Node
		void InsertAtBack(int data) {
			Node *temp = new Node;
			temp->Data = data;
			temp->next = 0;
			Node *current = head;
			while(current->next!=0)
				current = current->next;
			current->next = temp;
		}
		//Remove Data from Front
		void RemoveDataFromFront(void) {
			Node *temp = head;
			if(temp==0){
				cout << "\nException\n";
				exit(0);			
			}
			else {
				head = head->next;
				temp =0;
				delete temp;
			}
		}
		//Remove Data From Back
		void RemoveDataFromBack(void) {
			Node *temp = head;
			Node *var = head->next;
			if(temp==0) {
				cout << "\nException\n"; exit(0);
			}
			else {
				while(var->next!=0)
				{
					var = var->next; temp = temp->next;
				}
				temp->next = 0;
				var = 0;
			}
		} 
		//Delete All the list
		void DeleteAll(void) {
			Node *current = head;
			while(head->next!=0)
			{
				head = head->next;
				current->next = 0;
				delete current;
				current = head;
			}
//			head = 0;
//			head->next = 0;
		}
		
		
		//Reverse the Linked List
		void Reverse_Linked_list(void) {
			Node *current = head;
			Node *last = 0;
			Node *Next = 0;
			while(current!=0) 
			{
				Next = current->next;
				current->next = last;
				last = current;
				current = Next;
			}
			head = last;
		}
		void print_data(void) {
			Node *temp = head;
			while(temp != 0)
			{
				cout << temp->Data << " ";
				temp = temp->next;
			}
		}
		
};
int main()
{
	SinglyLinkedlist sl1(1);
	//sl1.print_data();
	SinglyLinkedlist s1(sl1);
	s1.print_data();
	cout << "\nS1 insertion\n";
	s1.InsertAtBack(5);
	s1.print_data();
	cout<<"\nS1 At back\n";
	s1.InsertAtFront(90);
	s1.print_data();
//	cout<<"\nRemove\n";
//	s1.RemoveDataFromBack();
//	s1.print_data();
//	cout<<"\nRemove Front\n";
//	s1.RemoveDataFromFront();
	s1.Reverse_Linked_list();
	s1.print_data();
	s1.DeleteAll();
	s1.print_data();
	return 0;
}
