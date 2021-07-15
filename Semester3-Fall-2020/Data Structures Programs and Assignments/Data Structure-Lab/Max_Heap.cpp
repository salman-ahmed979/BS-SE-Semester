#include<iostream>
using namespace std;

class MaxHeap {

    private:
        int *arr;
        int capacity, heap_size;
    public:
        MaxHeap(int size) {
            capacity = size;
            heap_size = 0;
            arr = new int[capacity];
            for(int i=0; i < capacity; i++)
                arr[i] = 0;
        }

        ~MaxHeap() {
            delete [] arr;
            arr = 0;
            capacity = 0;
            heap_size = 0;
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

        //function to move inserted element to top
        //heap condition fulfill
        void shiftup(int inserted_value) {
            if(inserted_value == 0) return;

            //get the parent of newly inserted value
            int parent = getParent(inserted_value);
            if(parent < 0) return;
            if(arr[parent] < arr[inserted_value]) {
                swap(arr[parent], arr[inserted_value]);
                //base case until the parent is max
                shiftup(parent);
            }          
        }

        //insert an element
        void insert(int value) {
            if(heap_size < capacity) {
                arr[heap_size] = value;
                shiftup(heap_size);
                heap_size++;
            }
        }

        bool isleaf(int value) {
            if(value >= heap_size) return true;
            return false;
        }

        //function to move element to downword 
        void shiftdown(int value) {
            //get left and right child
            int left_child = getLeft(value);
            int right_child = getRight(value);

            int max_index = value;
            if(!isleaf(left_child) && arr[left_child] > arr[value])
                max_index = left_child;
            if(!isleaf(right_child) && arr[right_child] > arr[max_index])
                max_index = right_child;

            if(max_index != value)
            {
                swap(arr[max_index], arr[value]);
                shiftdown(max_index);
            }
        }

        //function to remove the value
        int remove(int i) {
            int value = arr[i];
            arr[i] = arr[heap_size-1];
            heap_size--;
            int parent = getParent(i);
            if(i == 0 || arr[i] < arr[parent])
                shiftdown(i);
            else
            {
                shiftup(i);
            }
            return value;
        }

        //function to get the maximum value
        int getMaximum(void) {
            int max = arr[0];
            arr[0] = arr[heap_size-1];
            heap_size--;
            shiftdown(0);
            return max;
        }

        void printHeap(void) {
            for(int i=0; i < heap_size; i++)
                cout << arr[i] << " ";
        }
};
int main() {
    MaxHeap m1(5);
    m1.insert(3); m1.insert(5); m1.insert(0); m1.insert(8);
    m1.insert(10);
    m1.printHeap();
    m1.remove(1);
    m1.printHeap();
    m1.insert(100);
    cout << "\nGet Maximum: " << m1.getMaximum();
    return 0;
}