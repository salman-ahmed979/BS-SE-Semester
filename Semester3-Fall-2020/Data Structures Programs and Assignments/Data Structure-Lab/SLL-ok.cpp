#include<iostream>
using namespace std;
struct Node {
	int Data;
	Node *next;
};
class SLL {
	private:
		Node *head, *tail;
	public:
		SLL() {
			head = 0;
		}
		SLL(int d) {
			//head = 0;
			Node *temp = new Node;
			temp->Data = d;
			temp->next = 0;
			head = temp;
			
			tail = temp;
		}
		SLL(const SLL& rhs) {
			Node *current = rhs.head;
			Node *last = head;
			while(current != 0) {
				
				if(head == 0) {
					
				}
			}
		}
		void InsertAtEnd(int d) {
			Node *temp = new Node;
			temp->Data = d;
			temp->next = 0;
			
			if(head == 0) {
				head = temp;
				tail = temp;
			}
			else {
				tail->next = temp;
				tail = temp; 
			}
		}
		void Print(void) {
			Node *current = head;
			while(current != 0) {
				cout << current->Data << " ";
				current = current->next;
			}
		}
		int get_size(void) {
			Node *current = head;
			int count = 0;
			while(current != 0) {
				count++; current = current->next;
			}
			return count;
		}
		void Swap(int p, int q) { //p & q are index
			
			if(!(p <= get_size() && q <= get_size() ))
				return;
			
			Node *currentp = head;
			int count = 0;
			Node *ptr, *qtr;
			while(currentp != 0) {
				if(count == p) 
				{
					break;
				}
				count +=1;
				ptr = currentp;
				currentp = currentp->next;
			}
			Node *currentq = head;
			count = 0;
			while(currentq != 0) {
				if(count == q) 
				{
					break;
				}
				count +=1;
				qtr = currentq;
				currentq = currentq->next;
			}
			
			//Case for if any pointer is on Head
			
			//Adjacent Nodes && Nodes in Between
			//Not for tail or head
			if(currentp!=head) {
			Node *temp = currentq->next;
			ptr->next = currentq;
			Node *temp2 = currentp->next;
			if(temp2 != qtr && currentq!=temp2) 
				currentq->next = temp2;
			else
				currentq->next = qtr;
			qtr->next = currentp;
			currentp->next = temp;
		}
		else if(currentp == head){
			Node *temp = currentp;
			head = head->next;
			temp->next = currentq->next;
			qtr->next = temp;
			currentq->next = head;
			head = currentq;
		}
		}
		
		void BubbleSort(void) {
			for(int i=0; i<get_size()-1; i++) {
				for(int j = i; j<get_size()-i; j++) {
					Node *current = head;
					if(current->Data < current->next->Data)
						Swap(j, j+1);
					current = current->next;
				}
			}
		}
		Node* getHead(void) {
			return head;
		}
		Node* Reverse_recursion(Node *current) {
			if(current==0) {
				return current;		
			}
			if(current->next == 0) {
				head = current;
				return current;
			}
			Node *node1= Reverse_recursion(current->next);
			node1->next = current;
			current->next = 0;
			return current;
		}
		
		void Permutation(void) {
			Node *current = head;
			Node *traverse = current->next;
			//tail->next = head;
			int permute = 1;
			for(int i=get_size(); i>=1; i--) {
				permute = i*permute;
			}
			int count = 0, counter = 0;
			while(count != permute) {
				
				cout << current->Data << " "; counter++;
				cout << traverse->Data << " ";
				Node *Printer = head;
				while(Printer != 0) {
					if(Printer != current && Printer != traverse) 
						cout << Printer->Data << " ";
					Printer  = Printer->next;
				}
				if(counter == permute/get_size()) {
			        current = current->next; 
					counter = 0;
				}
				if(current->next == 0)
					traverse = head;
				else
					traverse = current->next;
				count++;
				cout << "\n";
			}	
		}
};
int main() {
	SLL s1;
//	for(int i=0; i<3; i++)
//		s1.InsertAtEnd(i);
	s1.InsertAtEnd(5); s1.InsertAtEnd(3); s1.InsertAtEnd(6);
	s1.Print(); cout << "\n";
	//s1.Swap(0,7);
	//s1.Print();
	//s1.BubbleSort();
	cout << "\n";
	s1.Permutation();

	return 0;
}
