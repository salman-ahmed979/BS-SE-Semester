#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

class Node{
	public:
		int data;
		Node *left;
		Node *right;
		
		Node(int d)
		{
			data = d;
			left = NULL;
			right = NULL;
		}
};

class BT{
	public:
		Node *root;
		int sum;
		int check_sum;
		
		BT()
		{
			sum = 0;
			check_sum = 0;
			root == NULL;
		}
		
		void inorder(Node *r)
		{
			if(r != NULL)
			{
				inorder(r->left);
				cout<<r->data<<" ";
				inorder(r->right);
			}
		}
		
		void insert(int d, Node *r)
		{
			queue <Node*>  q;
			q.push(r);
			
			while(!q.empty())
			{
				r = q.front();
				q.pop();
				
				if(r->left == NULL)
				{
					r->left = new Node(d);
					break;
				}
				else
				{
					q.push(r->left);
				}
				
				if(r->right == NULL)
				{
					r->right = new Node(d);
					break;
				}
				else
				{
					q.push(r->right);
				}
			}
		}
		
		void solve(Node *r)
		{
			if(r == NULL)
			{
				return;
			}
			else
			{
				ofstream outfile;
				outfile.open("output1.txt");
				queue <Node*>  q;
				q.push(r);
				Node *prev;
				
				while(!q.empty())
				{
					Node *p = q.front();
					outfile<<p->data<<" ";
					sum = sum + p->data;
					
					if((sum == check_sum))
					{
						return;
					}
					q.pop();
					if(p->left != NULL)
					{
						q.push(p->left);
					}
					if(p->right != NULL)
					{
						q.push(p->right);
					}
				}
			}
		}
		
		void input()
		{
			ifstream infile;
			infile.open("input1.txt");
			int c;
			infile>>c;
			infile>>check_sum;
			int d;
			int i = 1;
			infile>>d;
			root = new Node(d);
			while(i < c)
			{
				infile>>d;
				insert(d, root);
				i++;
			}
		}
};

int main(void)
{
	BT A;
	A.input();
	A.inorder(A.root);
	cout<<endl;
	A.solve(A.root);
	return 0;
}
