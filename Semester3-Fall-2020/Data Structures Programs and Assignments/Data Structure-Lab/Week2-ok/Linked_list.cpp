#include<iostream>
using namespace std;
struct node{
	int Data;
	node *next;
};
class linked_list{
	node *head, *tail;
	public:
		linked_list()
		{
			head  = NULL; tail = NULL;
		}
		//Function of adding a Node
		void add_node(int n)
		{
			node *temp = new node;
			temp->Data = n;
			temp->next = NULL;
			if(head==NULL)
			{
				head = temp;
				tail = temp;
			}
			else{
				tail->next = temp;
				tail = tail->next;
			}
		}
		//Function of printing a Node
		void print_node(void)
		{
			node *temp = head;
			while(temp!=NULL)
			{
				cout << temp->Data << " ";
				temp = temp->next;
			}
		}
		//Average function
		void average_node(linked_list &li)
		{
			node *temp = li.head;
			int avg = 0;
			for(int i=0; i<12; i++)
			{
				if(temp!=NULL)
				{
				int sum = 0;
				node *cal = temp;
				for(int j=0; j<4; j++)
				{
					sum += cal->Data;
					cal = cal->next;
				}
				avg = sum / 4;
				cout << "\nError\nAvg: " << avg;
				add_node(avg);
				cout << "\nIn avg\n";
				temp = temp->next;
				avg = 0;
				delete cal;
				}
			}
		}
};
int main()
{
	/*
	linked_list l1;
	for(int i=0; i<12; i++)
	{
		int n;
		cout << "\nEnter number: ";
		//cin >> n;
		l1.add_node(i);
	}
	linked_list l2;
	l2.average_node(l1);
	cout << "\n\nLinked List Number List\n\n";
	l1.print_node();
	cout << "\n\nAverage Linked List\n\n";
	l2.print_node();
	*/
	int n=312, sum=0;
	while(n>0)
	{
		int r = n%10;
		sum+=r;
		n = n/10;
	}
	cout << "\nSum: " << sum;
	return 0;
}
