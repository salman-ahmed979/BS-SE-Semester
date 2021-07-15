#include<iostream>
using namespace std;
template<class T>
struct Node {
	T Data;
	Node<T> *next;
//	public:
//		Node() {
//			Data = 0; next = 0;
//		}
//		Node(T data) {
//			Data = data; next = 0;
//		}
//		Node(T data, Node<T> *ptr) {
//			Data = data; next = ptr;
//		}
//		T& getNext() const {
//			return *next;
//		}
};
template<class T>
class SinglyLinkedList { 
	private:
		Node<T> *head;
	public:
		SinglyLinkedList() {
			head = 0;
		}
		//Parameterzied Const
		SinglyLinkedList(T data) {
			Node<T> *temp;
			temp->Data = data;
			temp->next = 0;
			this->head = temp;
			delete temp;
		}
		//Copy Constructor
		SinglyLinkedList(const SinglyLinkedList& rhs) {
			Node<T> *current = rhs.head;	
			this->head = 0;
			Node<T> *last = head;
			while(current!=0)
			{
				Node<T> *temp;
				temp->Data = current->Data;
				if(head==0)
				{
					head = temp;
					last = head;
				}
				last->next = temp;
				last = temp;
				current = current->next;
			}
		}
		//Print Function
		void print(void) {
			Node<T> *current = head;
			while(current != 0) {
				cout << "Value: " << current->Data << endl;
				current = current->next;
			}
		}
};
int main()
{
	//SinglyLinkedList<int>s1(5);
	//s1.print()
	cout<<"hello";
	SinglyLinkedList <int> s1(2);
	return 0;
}

