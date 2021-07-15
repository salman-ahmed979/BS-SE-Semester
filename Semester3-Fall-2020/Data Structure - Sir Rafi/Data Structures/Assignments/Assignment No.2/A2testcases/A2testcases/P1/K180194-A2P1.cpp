#include<iostream>
#include<fstream>
using namespace std;

class Node{
	public:
		int co_efficient;
		char base;
		int exponent;
		Node *next;
		Node *prev;
		
		Node()
		{
			co_efficient = 0;
			base = ' ';
			exponent = 0;
			next = NULL;
			prev = NULL;
		}
		
		Node(int c, char b, int e)
		{
			co_efficient = c;
			base = b;
			exponent = e;
			next = NULL;
			prev = NULL;
		}
		
		Node(int c, char b, int e, Node *n, Node *p)
		{
			co_efficient = c;
			base = b;
			exponent = e;
			next = n;
			prev = p;
		}
};

class LinkedList{
	private:
		Node *head, *tail;
	public:
		LinkedList()
		{
			head = NULL;
			tail = NULL;
		}
		
		void get_data(LinkedList &L2)
		{
			Node *temp = head;
			ifstream infile;
			infile.open("input1.txt");
			int c;
			char b;
			char p;
			int e =1;
			
			while(e != 0)
			{
				infile>>c;
				infile>>b;
				infile>>p;
				infile>>e;
				this->insert_at_tail(c, b, e);
			}
			infile>>p;
			infile>>p;
			
			e =1;
			while(e != 0)
			{
				infile>>c;
				infile>>b;
				infile>>p;
				infile>>e;
				L2.insert_at_tail(c, b, e);
			}
		}
		
		
		void insert_at_tail(int c, char b, int e)
		{
			if(head == NULL)
			{
				Node *newNode = new Node(c, b, e);
				head = tail = newNode;
			}
			else
			{
				Node *newNode = new Node(c, b, e, NULL, tail);
				tail->next = newNode;
				tail = tail->next;
			}
		}
		
		void insert_at_head(int c, char b, int e)
		{
			if(head == NULL)
			{
				Node *newNode = new Node(c, b, e);
				head = tail = newNode;
			}
			else
			{
				Node *newNode = new Node(c, b, e, head, NULL);
				head->prev = newNode;
				head = newNode;
			}
		}
		
		void insert_at_index(int index, int c, int b, int e)
		{
			if(head == NULL || index == 0)
			{
				Node *newNode = new Node(c, b, e);
				head = tail = newNode;
			}
			else if(index == size())
			{
				Node *newNode = new Node(c, b, e, NULL, tail);
				tail->next = newNode;
				tail = newNode;
			}
			else
			{
				Node *temp = head;
				int i = 1;
				while(i < index)
				{
					temp = temp->next;
					i++;
				}
				Node *newNode = new Node(c, b, e, temp->next, temp);
				temp->next = newNode;
				temp->next->prev = newNode;
			}
		}
		
		int size()
		{
			int c = 0;
			Node *temp = head;
			while(temp != NULL)
			{
				temp = temp->next;
				c++;
			}
			return c;
		}
		
		LinkedList merge(LinkedList L1, LinkedList L2)
		{
			LinkedList result;
			Node *temp1 = L1.head;
			while(temp1 != NULL)
			{
				result.sorted_insert(temp1->co_efficient, temp1->base, temp1->exponent);
				temp1 = temp1->next;
			}
			Node *temp2 = L2.head;
			while(temp2 != NULL)
			{
				result.sorted_insert(temp2->co_efficient, temp2->base, temp2->exponent);
				temp2 = temp2->next;
			}
			LinkedList r;
			Node *temp = result.head;
			r.insert_at_tail(temp->co_efficient, temp->base, temp->exponent);
			temp = temp->next;
			while(temp != NULL)
			{
				r.insert_at_tail(temp->co_efficient, temp->base, temp->exponent);
				temp = temp->next;
			}
			return r;
		}
		
		int return_index(int e)
		{
			int i=0;
			Node *temp = head;
			while(temp->exponent != e)
			{
				temp = temp->next;
				i++;
			}
			return i;
		}
		
		void display()
		{
			Node *temp = head;
			while(temp != NULL)
			{
				cout<<temp->co_efficient<<temp->base<<"^"<<temp->exponent<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
		
		void sorted_insert(int c, char b, int e)
		{
			if(head == NULL)
			{
				Node *newNode = new Node(c, b, e);
				head = tail = newNode;
			}
			else
			{
				Node *temp = head;
				int max = e;
				while(temp != NULL)
				{
					if(max > temp->exponent)
					{
						max = temp->exponent;
						break;
					}
					temp = temp->next;
				}
				if(max == e)
				{
					insert_at_tail(c, b, e);
				}
				else
				{
					int i = return_index(max);
					insert_at_index(i, c, b, e);
				}
			}
		}
		
		LinkedList add(LinkedList result)
		{
			LinkedList sum;
			Node *temp;
			temp = result.head;
			int s=0;
			
			while(temp->next != NULL)
			{
				if(temp->exponent == temp->next->exponent)
				{
					s = temp->co_efficient + temp->next->co_efficient;
					sum.insert_at_tail(s, temp->base, temp->exponent);
					temp = temp->next;
				}
				else if(temp->prev->exponent == temp->exponent)
				{
					temp = temp->next;
				}
				else
				{
					sum.insert_at_tail(temp->co_efficient, temp->base, temp->exponent);
					temp = temp->next;
				}
			}
			return sum;
		}
		
		LinkedList derivative(LinkedList result)
		{
			LinkedList derivate;
			Node *temp = result.head;
			int c;
			int e;
			while(temp != NULL)
			{
				{
					c = temp->co_efficient * temp->exponent;
					e = temp->exponent - 1;
					derivate.insert_at_tail(c, temp->base, e);
				}
				temp = temp->next;
			}
			return derivate;
		}
		
		void write_data1()
		{
			Node *temp1 = head;
			ofstream outfile1;
			outfile1.open("output1.1.txt");
			while(temp1->next != NULL)
			{
				if(temp1->co_efficient > 0)
				{
					outfile1<<"+";
				}
				if(temp1->co_efficient == 0)
				{
					temp1 = temp1->next;
				}
				outfile1<<temp1->co_efficient<<temp1->base<<"^"<<temp1->exponent;
				temp1 = temp1->next;
			}
			outfile1<<"=";
			outfile1<<"0";
		}
		
		void write_data2()
		{
			Node *temp1 = head;
			ofstream outfile1;
			outfile1.open("output1.2.txt");
			while(temp1->next != NULL)
			{
				if(temp1->co_efficient > 0)
				{
					outfile1<<"+";
				}
				if(temp1->co_efficient == 0)
				{
					temp1 = temp1->next;
				}
				outfile1<<temp1->co_efficient<<temp1->base<<"^"<<temp1->exponent;
				temp1 = temp1->next;
			}
			outfile1<<"=";
			outfile1<<"0";
		}
};

int main(void)
{
	LinkedList L1;
	LinkedList L2;
	L1.get_data(L2);
	LinkedList merged;
	LinkedList sum;
	merged  = L1.merge(L1, L2);
	sum = L1.add(merged);
	sum.write_data1();
	LinkedList d;
	d = L1.derivative(sum);
	d.write_data2();
	cout<<"The contents have been written successfully to the file";
	return 0;
}
