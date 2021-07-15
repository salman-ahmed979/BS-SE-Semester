#include<iostream>
using namespace std;
struct Node {
	int process, quota, cpu_process;
	Node *next;
};
class Queue{
	private:
		Node *front, *rear;
		int *array_solution, size;
	public:
		Queue(int n) {
			front = 0; rear = 0;
			array_solution = new int [n]; size = 0;
		}
		void EnQueue(int inpt_process, int inpt_qt, int inpt_cpu_procs) {
			//Create New temp Queue Node
			Node *temp = new Node;
			temp->process = inpt_process;
			temp->quota = inpt_qt;
			temp->cpu_process = inpt_cpu_procs;
			temp->next = 0;
			
			//Check if No queue
			if(front == 0) {
				front = temp; 
				rear = temp;
			}
			else {
				rear->next = temp;
				rear = temp;
			}
		}
		
		void DeQueue(void) {
			Node *temp = front;
			front = front->next;
			if(front == 0) return;
			temp->cpu_process -= temp->quota;
			if(temp->cpu_process > 0) {
				EnQueue(temp->process, temp->quota, temp->cpu_process);
				temp->next = 0;
				delete temp;
				temp = 0;
			}
			else {
				array_solution[size] = temp->process;
				size++;
				temp->next = 0;
				delete temp;
				temp = 0;
			}
		}
		//Calculating Quota & result
		void Process_Solution(void) {
			
			while(front != 0) {
				DeQueue();				
			}
		}
		
		void Print_Solution(void) {
			for(int i=0; i<size; i++)
				cout << array_solution[i] << " ";
		}
};
int main(){
	int **arr;
	
	//Input Size
	int n;
	cin >> n;
	arr = new int*[3];
	
	for(int i=0; i<3; i++) {
		arr[i] = new int[n];
	}
	
	//Inputting Values
	for(int i=0; i<3; i++) {
		for(int j=0; j<n; j++)
			cin >> arr[i][j];
	}
	
	Queue q1(n);
	for(int i=0; i<n; i++) {
		q1.EnQueue(arr[0][i], arr[1][i], arr[2][i]);
	}
	
	q1.Process_Solution();
	q1.Print_Solution();
	return 0;
}
