#include<iostream>
using namespace std;

struct Node {
	int Data;
	Node *next;
};
class SinglyLinkedList{
	private:
		Node *head;
	public:
		SinglyLinkedList() {
			head = 0;
		}
		SinglyLinkedList(int d) {
			Node *temp = new Node;
			temp->Data = d;
			temp->next = 0;
			head->next = temp->next;
			head = temp;
		}
		~SinglyLinkedList() {
			if(head != 0) {
				delete head;
				head = 0;
			}
		}
		//Inserting Node At back
		void InsertAtBack(int d) {
			Node *temp = new Node;
			temp->Data = d;
			temp->next = 0;
			if(head == 0) {
				head = temp;
				head->next = temp->next;
			}
			else {
				Node *current = head;
				while(current->next != 0) 
					current = current->next;
				current->next = temp;
			}
		}
		//Printing Node
		void Print(void) {
			Node *current = head;
			while(current != 0) {
				cout << current->Data << " ";
				current = current->next;
			}
		}
		//Swapping Node
		void Swap_Node(int p, int q) {
			if(p == q)
				return;
			Node *previous_p = 0, *current_p = head;
			while(current_p && current_p->Data != p) {
				previous_p = current_p;
				current_p = current_p->next;
			}
			
			Node *previous_q = 0, *current_q = head;
			while(current_q && current_q->Data != q) {
				previous_q = current_q;
				current_q = current_q->next;
			}
			if(current_p == 0 || current_q == 0)
				return;
			//Swapping Case of Any head, Adjacent & Arbitrary Places
			bool var = false;
			if(current_p == head && current_p->next != current_q) {
				head = current_p->next;
				current_p->next = current_q->next;
				previous_q->next = current_p;
				current_q->next = head;
				head = current_q;
			}
			else if(current_q == head && current_q->next != current_p){
				head = current_q->next;
				current_q->next = current_p->next;
				previous_p->next = current_q;
				current_p->next = head;
				head = current_p;
				var = true;
			}
			else if(current_p->next == current_q && var == false) {
				Node *temp = 0;
				if(current_q->next == 0)
					temp = 0;
				else
					temp = current_q->next;
				current_q->next = current_p;
				if(current_p == head)
					head = current_q;
				else
					previous_p->next = current_q;
				current_p->next = temp;
				var = true;
			}
			else if(current_q->next == current_p && var == false) {
				Node *temp = current_p->next;
				current_p->next = current_q;
				if(current_q == head)
					head = current_p;
				else
					previous_q->next = current_p;
				current_q->next = temp;
				var = true;
			}
			else {
				Node *temp = current_p->next;
				previous_q->next = current_p;
				current_p->next = current_q->next;
				previous_p->next = current_q;
				current_q->next = temp;
			}
		}
		int get_size(void) {
			Node *current = head;
			int count = 1;
			while(current != 0) {
				count++;
				current = current->next;
			}
			return count;
		}
		void BubbleSort(void) {
			
			int i = 1;
			while(i <= get_size()) {
				Node *current = head;
				while(current->next != 0) {
					if(current->Data > current->next->Data) {
						int p = current->Data, q = current->next->Data;
						Swap_Node(p, q);		
					}
					current = current->next;
				}
				i++;
			}
		}
		void BubbleSort_version(void) {
			for(int i=0; i<get_size(); i++) {
				Node *current = head;
				Node *nexter = current->next;
				for(int j=i+1; j<get_size()-i; j++) {	
					if(current->Data > nexter->Data)
						Swap_Node(current->Data, nexter->Data);
					current = nexter; nexter = nexter->next;
				}
			}
		}
		void SelectionSort(void) {
			Node *current = head;
			Node *traverse = head;
			for(int i=0; i<get_size()-1 && current != 0; i++) {
				int min = current->Data;
				Node *nexter = current->next;
				for(int j=i+1; j<get_size() && nexter !=0; j++) {
					if(nexter->Data < min) 
						min = nexter->Data;
					nexter = nexter->next;
				}
				if(current->Data != min) {
					Swap_Node(current->Data, min);
				}
				traverse = traverse->next;
				current = traverse;
			}
		}
		void InsertionSort(void) {
			Node *temp = 0, *thead = 0;
			Node *current = head;
			while(current != 0) {
				Node *nexter = current->next;
				if(temp == 0) {
					Node *chk = current;
					chk->next = 0;
					temp = chk;
					thead = temp;
				}
				else {
					Node *trav = thead;
					while(trav->next != 0 && trav->next->Data < current->Data)
						trav = trav->next;
					current->next = trav->next;
					trav->next = current;
				}
				current = nexter;
			}
			head = temp;
		}
};
int main() {
	SinglyLinkedList s1;
	for(int i=0; i<5; i++)
		s1.InsertAtBack(i);
	s1.InsertAtBack(12);
	s1.InsertAtBack(10);
//	for(int i=4,j=0; i>2; i--)
//	{
//		s1.Swap_Node(i,j);
//		j++;
//	}
	s1.BubbleSort_version();
	s1.SelectionSort();
	s1.InsertionSort();
	s1.Print();
	return 0;
}
