#include<iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};
class StackLinkedList {
	private:
		Node *head, *top;
		int size;
	public:
		StackLinkedList() {
			head = 0;
			top = 0; size = 0;
		}
		void Push(int data) {
			Node *temp = new Node;
			temp->data = data; temp->next = 0;
			if(head == 0) {
				head = temp;
				top = temp;
			}
			else {
				temp->next = top;
				top = temp;
			}
			size++;
		}
		int Peek(void) {
			return top->data;
		}
		void Pop(void) {
			top = top->next;
			size--;
		}
		void Print(void) {
			Node *current = top;
			while(current != head) {
				cout << current->data << " ";
				current = current->next;
			}
			cout << current->data << "\nSize: " << size;
		}
};
int main() {
	StackLinkedList s1;
	for(int i=0; i<5; i++)
		s1.Push(i);
	cout << "\nPeek: " << s1.Peek();
	s1.Pop();
	cout << "\nPeek: " << s1.Peek();
	cout << "\nPrinting data: "; s1.Print();
	return 0;
}
