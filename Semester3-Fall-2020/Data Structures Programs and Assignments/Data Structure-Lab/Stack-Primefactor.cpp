#include<bits/stdc++.h>
using namespace std;
//Implementing Stack
class Stack{
	private:
		int top;
		int *Data;
		int MAX_SIZE;
	public:
		Stack(int n) {
			MAX_SIZE = n;
			Data = new int[MAX_SIZE];
			memset(Data, 0, sizeof(int)*MAX_SIZE);
			top = -1;
		}
		void Push(int d) {
			if(top <= MAX_SIZE-1) {
				top += 1;
				*(Data+top) = d;	
			}
			else
				cout << "\nStack is Full\n";
		}
		bool IsEmpty(void) {
			if(top < 0)
				return true;
			return false;
		}
		bool IsFull(void) {
			if(top == MAX_SIZE-1)
				return true;
			return false;
		}
		int Pop(void) {
			if(IsEmpty()) 
				return 0;
			int data = *(Data+top);
			top -= 1;
			return data;
		}
		int Peek(void) {
			if(IsEmpty())
				return 0;
			return *(Data+top);
		}
		//Implementing Q # 4
		void Reverse_Stack(Stack &otherstack) {
			if(this->top > 0) {
				delete []Data;
				Data = 0;
			}
			int other_top = otherstack.top;
			while(otherstack.top >= 0) {
				this->top += 1;
				*(Data+top) = *(otherstack.Data+otherstack.top);
				otherstack.top -= 1;
			}
			otherstack.top = other_top;
		}
		//Print Data of stack
		void Print(void) {
			if(IsEmpty())
				return;
			for(int i=0; i<=top; i++) {
				cout << *(Data+i) << " ";
			}
		}
		bool IsPrime(int value) {
			int count = 2;
			while(count >= 9) {
				if(value % count == 0 && value != count)
					return false;
				count++;
			}
			return true;
		}
		void Prime_Factor(int d) {
			int count = 2;
			while(d > 1) {
				if(d%count == 0) {
					if(IsPrime(count) && this->Peek() != count) {
						Push(count);
					}
					d /= count;
				}
				else {
					count++;
				}
			}
		}
};
int main() {
	Stack s1(5);
	/*
	for(int i=0; i<5; i++)
		s1.Push(i);
	cout << "\nUsing Peek: " << s1.Peek();
	cout <<"\nPop: " << s1.Pop();
	Stack s2(5);
	s2.Reverse_Stack(s1);
	cout << "\nPrinting Stack 2 with Reverse Data of Stack 1\n";
	s2.Print();*/
	s1.Prime_Factor(49);
	cout << "\nPrinting Stack 1\n";
	s1.Print();
	return 0;
}