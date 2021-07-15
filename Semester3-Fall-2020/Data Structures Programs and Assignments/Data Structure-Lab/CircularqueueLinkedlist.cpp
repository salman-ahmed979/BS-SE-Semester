#include<iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};

class CircularQueueLinkedList {
    private:
        Node *front, *rear;
    public:
        CircularQueueLinkedList() {
            front = 0; rear = 0;
        }

        void insert(int d) {
            Node *temp = new Node;
            temp->data = d;
            temp->next = 0;

            if(front == 0) {
                front = temp;
                rear = temp;
                rear->next = front;
            }
            else
            {
                rear->next = temp;
                rear = temp;
                rear->next = front;
                // delete temp;
                // temp = 0;
            }
        }

        void print(void) {
            Node *current = front;
            while(current->next != front) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << current->data << "\n";
        }

        int remove(void) {
            Node *temp = front;
            front = front->next;
            rear->next = front;
            int r = temp->data;
            delete temp;
            temp = 0;
            return r;
        }
};
int main() {
    CircularQueueLinkedList l1;
    l1.insert(5);
    l1.insert(12);
    l1.insert(33);
    l1.insert(54);
    l1.print();
    cout << "\nRemoved: " << l1.remove() << "\n";
    l1.print();
    l1.insert(100);
    cout << "\nInserted 100\n";
    l1.print();
    return 0;
}