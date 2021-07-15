#include<iostream>
using namespace std;
struct Node {
	int Data;
	Node *next;
};

class SinglyLinkList {
	private:
		Node *head;
	public:
		~SinglyLinkList() {
			head = 0;
			delete head;
		}
		SinglyLinkList() {
			head = 0;
		}
		
		SinglyLinkList(int d) {
			Node *temp = new Node;
			temp->Data = d;
			temp->next = 0;
			head = temp;
			head->next = 0;
		}
		
		SinglyLinkList(const SinglyLinkList& rhs) {
			Node *current = rhs.head;
			Node *last = head;
			
			while(current !=0) {
				Node *temp = current;
				if(head==0) {
					head = temp; last = temp;
				}
				else {
					last->next = temp;
					last = temp;
				}
				current = current->next;
			}
		}
		
		SinglyLinkList& operator=(const SinglyLinkList& rhs) {
			if(this != &rhs) {
				while(head != 0) {
					Node *temp = head;
					head = head->next;
					temp->next = 0;
					delete temp; temp = 0;
				}
				head = 0;
				Node *current = rhs.head;
				Node *last = head;
				while(current != 0) {
					Node *temp = current;
					if(head == 0) {
						head = temp; last = temp;
					}
					else {
						last->next = temp;
						last = temp;
					}
					current = current->next;
				}
			}
			return *this;
		}
		
		void InsertAtLast(int d) {
			Node *current = head;
			Node *temp = new Node;
			temp->Data = d;
			temp->next = 0;
			while(current->next != 0) 
				current = current->next;
			current->next = temp;
			current = temp;
		}
				
		void InsertAtFirst(int d) {
			Node *temp = new Node;
			temp->Data = d; temp->next = head;
			head = temp;
		}
		
		void ReverseNode(void) {
			Node *current = head;
			Node *Next = 0, *last = 0;
			while(current != 0) {
				Next = current->next;
				current->next = last;
				last = current;
				current = Next;
			}
			head = last;
		}
		
		void Print_list(void) {
			Node *current = head;
			while(current != 0) {
				cout << current->Data << " "; current = current->next;
			}
		}
		
		void InsertAt_Index(int index, int d) {
			int count = 1;
			Node *current = head;
			if(index == 0) {
				Node *temp = new Node;
				temp->Data = d; temp->next = current;
				head = temp;
				return;
			}
			while(count!=index) {
				count++;
				current = current->next;
			}
			Node *temp = new Node;
			temp->Data = d; temp->next = current->next;
			current->next = temp;
		}
		
		void MergeNodes(SinglyLinkList &s1, SinglyLinkList&s2) {
			Node *temp1 = s1.head;
			Node *temp2 = s2.head;
			while(temp1 != 0 && temp2 != 0) {
				if(temp1 !=0 && temp2!=0) {
					if(temp1->Data < temp2->Data)
						this->InsertAtLast(temp1->Data);
					else
						this->InsertAtLast(temp1->Data);
				}
				temp1 = temp1->next; temp2 = temp2->next;
			}
		}
		
		void Intersection_list(SinglyLinkList s1, SinglyLinkList s2) {
			Node *current1 = s1.head;
			Node *current2 = s2.head; bool var = false;
			while(1) {
				while(current2 != 0) {
					while(current1 != 0) {
						if(current1->next == current2->next)
						{
							var = true; cout << "\nIntersected Node: " << current1->next << " Data: " << current1->next->Data; break;
						}
						current1 = current1->next;
					}
					if(var == true)
						break;
					current2 = current2->next;
					current1 = 0;
					current1 = head;
				}
				if(var == true)
					break;
				else
					break;
			}
		}
		
		void Delete_duplicate(void) {
			Node *current = head;
			Node *temp = current->next;
			Node *addr = current;
			while(current != 0) {
				while(temp != 0) {
					if(current->Data == temp->Data) {
						addr->next = temp->next;
					}
					temp = temp->next;
					addr = addr->next;
				}
				current = current->next;
				temp = 0;
				temp = current->next->next;
				addr = 0;
				addr = current;
			}	
		}
		
		//Remove certain number from linklist
		void Remove_Value(int val) {
			Node *current = head;
			if(head->Data == val) {
				Node *temp = head;
				head = head->next;
				delete temp;
				temp = 0;
				current = head;
			}
			Node *prev = 0;
			while(current != 0) {
				prev = current;
				current = current->next;
				if(current->Data == val) {
					prev->next = current->next;
					current = prev->next;
				}
			}
		}
};
int main() {
	SinglyLinkList s1(8);
	int n;
	for(int i=1; i<=3; i++) {
		cout << "\nEnter number: "; cin >> n;
		s1.InsertAtLast(n);
	}
	s1.Print_list();
	// s1.InsertAt_Index(0,20); cout << "\n";
	// s1.Print_list();
	// s1.ReverseNode();
	// cout << "\n";
	// s1.Print_list();
	// s1.Delete_duplicate();
	cout << "\nRemoving val\n";
	s1.Remove_Value(2);
	s1.Print_list();
	return 0;
}
