#include<iostream>
using namespace std;

class Min_Heap {
    private:
        int *arr;
        int heap_size;
        int capacity;
    public:
        Min_Heap(int size) {
            capacity = size;
            arr  = new int[capacity];
            heap_size = 0;
            for(int i=0; i < capacity; i++)
                arr[i] = 0;
        }
        ~Min_Heap() {
            delete [] arr;
            heap_size = 0;
            capacity  = 0;
        }

        int getParent(int child) {
            //Check for parent location
            //If child is right child
            if(child % 2 == 0) return (child / 2) - 1;
            //If child is left child
            return child / 2;
        }

        //function to get leftchild
        int getLeft(int parent) {
            return (2 * parent) + 1;
        }

        //function to get rightchild
        int getRight(int parent) {
            return (2 * parent) + 2;
        }

        int getsize(void) {
            return heap_size;
        }

        //function to swap the elements in array
        void swap(int &a, int &b) {
            int temp = a;
            a = b;
            b = temp;
        }

        bool isleaf(int value) {
            if(value >= heap_size) return true;
            return false;
        }
        
        //function to take minimum value to root
        void shiftup(int value_index) {
            if(value_index == 0) return;
            //get parent of value
            int parent = getParent(value_index);
            if(parent < 0) return; // base case
            if(arr[parent] > arr[value_index]) {
                swap(arr[parent], arr[value_index]);
                shiftup(parent);
            }
        }

        //function to take maximum value downward
        void shiftdown(int value_index) {
            int left_child = getLeft(value_index);
            int right_child = getRight(value_index);
            int min_index = value_index;
            if(!isleaf(left_child) && arr[left_child] < arr[value_index])
                min_index = left_child;
            if(isleaf(right_child) && arr[right_child] < arr[min_index])
                min_index = right_child;
            if(min_index != value_index) {
                swap(arr[min_index], arr[value_index]);
                shiftdown(min_index);
            }
        }

        void insert(int value) {
            if(heap_size < capacity) {
                arr[heap_size] = value;
                shiftup(heap_size);
                heap_size++;
            }
        }

        //function to remove the value
        int remove(int value_index) {
            int r = arr[value_index];
            arr[value_index] = arr[heap_size-1];
            heap_size--;

            if(value_index == 0 || arr[value_index] > arr[getParent(value_index)])
                shiftdown(value_index);
            else 
                shiftup(value_index);
            return r;
        }

        //function to get the minimum value
        int getMinimum(void) {
            int min = arr[0];
            arr[0] = arr[heap_size-1];
            heap_size--;
            shiftdown(0);
            return min;
        }

        //function to retain heap property
        void heapify(void) {
            for(int i=heap_size-1; i >= 0; i--)
                shiftdown(i);
        }

        void printHeap(void) {
            for(int i=0; i < heap_size; i++)
                cout << arr[i] << " ";
        }
};
int main(void) {
    Min_Heap m1(6);
    m1.insert(9); m1.insert(3); m1.insert(5); m1.insert(7); m1.insert(-3);
    m1.printHeap();
    cout << "\nInserting -10\n";
    m1.insert(-10);
    m1.printHeap();
    cout << "\nGet minimum: " << m1.getMinimum();
    return 0;
}