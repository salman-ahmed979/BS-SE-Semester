#include<iostream>
#include<fstream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		
		Node()
		{
			data = 0;
			next = NULL;
		}
		
		Node(int data)
		{
			this->data = data;
			next = NULL;
		}
		
		Node(int data, Node *next)
		{
			this->data = data;
			this->next = next;
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
		
		void get_data()
		{
			int n;
			int i=0;
			long int d;
			ifstream infile;
			infile.open("input2.txt");
			infile>>n;
			while(i < n)
			{
				infile>>d;
				insert_at_head(d);
				i++;
			}
		}
		
		void insert_at_head(int d)
		{
			if(head == NULL)
			{
				Node *newNode = new Node(d);
				head = tail = newNode;
			}
			else
			{
				Node *newNode = new Node(d, head);
				head = newNode;
			}
		}
		
		void insert_at_tail(int d)
		{
			if(head == NULL && tail == NULL)
			{
				Node *newNode = new Node(d);
				head = tail = newNode;
			}
			else
			{
				Node *newNode = new Node(d);
				tail->next = newNode;
				tail = tail->next;
			}
		}
		
		void insert_at_index(int index, int d)
		{
			if(head == NULL)
			{
				Node *newNode = new Node(d);
				head = tail = newNode;
			}
			else
			{
				Node *temp;
				temp = head;
				int i = 1;
				while(i < index)
				{
					temp = temp->next;
					i++;
				}
				Node *newNode = new Node(d, temp->next);
				temp->next = newNode;
			}
		}
		
		void delete_at_head()
		{
			if(head != NULL)
			{
				Node *temp;
				temp = head;
				head = head->next;
				delete temp;
			}
		}
		
		void delete_at_tail()
		{
				Node *temp;
				temp = head;
				while(temp->next != tail)
				{
					temp = temp->next;
				}
				delete tail;
				tail = temp;
				temp->next = NULL;
		}
		
		void display()
		{
			Node *temp;
			temp = head;
			while(temp != NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
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
		
		int element_at_index(int index)
		{
			if(index == 0)
			{
				return head->data;
			}
			else
			{
				Node *temp;
				temp = head;
				int i = 0;
				while(i < index)
				{
					temp = temp->next;
					i++;
				}
				return temp->data;
			}
		}
		
		LinkedList split()
		{
			LinkedList result;
			Node *temp = head;
			while(temp != NULL)
			{
				int val;
				int n = temp->data;
				while(n != 0)
				{
					val = n%10;
					result.insert_at_head(val);
					n/=10;
				}
				temp = temp->next;
			}
			return result;
		}
		
		void solve(LinkedList result)
		{
			int s = result.size();
			int arr[s];
			
			for(int i=0;i<s;i++)
			{
				arr[i] = result.element_at_index(i);
			}
			
			int key = 1;
			int left = 0;
			int right = 2;
			int max = 0;
			int maxl = 0;
			int maxr = 0;
			while(key != (s-1))
			{
				left = key-1;
				right = key+1;
				if(arr[left] != arr[right] || left < 0 || right >= (s-1))
				{
					key++;
					continue;
				}
				while(arr[left] == arr[right])
				{
					left--;
					right++;
				}
				if((right-left) >= max)
				{
					max = right-left;
					maxl = left+1;
					maxr = right;
				}
				key++;
			}
			
			//writing output to the file
			ofstream outfile;
			outfile.open("output2.txt");
			if(max != 0)
			{
				for(int i=maxl;i<maxr;i++)
				{
					outfile<<arr[i];
				}
			}
			else
			{
				outfile<<"No palindrome found";
			}
		}
};

int main(void)
{
	LinkedList max;
	LinkedList L;
	LinkedList result;
	L.get_data();
	result = L.split();
	L.solve(result);
	cout<<"file is created";
	cout<<endl;
}
