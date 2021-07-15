#include<iostream>
using namespace std;
struct Node {
    int Data;
    Node *next;
};
class SinglyLinkedList {
private:
    Node *head;
public:
    //Constructor
    SinglyLinkedList(int d) {
        Node *temp = new Node;
        temp->Data = d;
        temp->next = 0;
        if(head == 0) {
            head = temp;
        }
    }
    SinglyLinkedList() {
        head = 0;
        head->next = 0;
    }
    void AddNode(int d) {
    	Node *temp = new Node;
    	temp->Data = d;
    	temp->next = 0;
    	Node *current = head;
    	if(head == 0) {
    		head = temp;
    		head->next = 0;
		}
		else {
			while(current->next != 0) {
				current = current->next;
			}
			current->next = temp;
		}
	}
	void Print(void) {
		Node *current = head;
		while(current != 0) 
		{
			cout << current->Data << " ";
			current = current->next;
		}
	}
	void AddNodes(SinglyLinkedList *s1, SinglyLinkedList *s2) {
		
	}
};
int main() {
    SinglyLinkedList s1(4);
    return 0;
}
