#include<iostream>
using namespace std;

//Circular queue array
class CircularQueueArray {
    private:
        int *arr;
        int size, front, rear, count;
    public:
        CircularQueueArray(int s) {
            size = s;
            arr = new int[size];
            front = 0; rear = -1; count = 0;
        }

        ~CircularQueueArray() {
            delete [] arr;
            size = 0;
            rear = 0;
            front = 0;
            count = 0;
        }

        bool Isfull(void) {
            if(count == size) return true; 
            return false;
        }

        bool isEmpty(void) {
            if(count == 0) return true;
            return false;
        }

        void insert(int value) {
            if(Isfull()) {
                cout  << "\nQueue is Full\n"; return;
            } 
            count++;
            rear++;
            arr[rear] = value;
        }

        int remove(void) {
            if(isEmpty()) {
                cout << "\nQueue is Empty\n"; return 0;
            }
            int r = arr[front];
            count--;
            front++;
            return r;
        }

        void print(void) {
            for(int i=front; i <= rear; i++)
                cout << arr[i] << " ";
        }
};
int main(void) {
    CircularQueueArray q1(5);
    q1.insert(9);
    q1.insert(7);
    q1.insert(54);
    q1.insert(89);
    q1.insert(31);
    q1.print();
    cout << "\nValue removed: " << q1.remove() << "\n"; 
    q1.print();
    q1.insert(100); cout << "\nNewly inserted: 100\n";
    q1.print();
    return 0;
}