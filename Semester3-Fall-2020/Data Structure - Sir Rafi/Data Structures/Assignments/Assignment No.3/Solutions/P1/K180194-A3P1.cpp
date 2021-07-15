#include<iostream>
#include<fstream>
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

class BST{
	public:
		Node *root;
		Node *maxroot;
		int maxr;
		int maxl;
		
		BST()
		{
			root = NULL;
			maxroot = NULL;
			maxr = 0;
			maxl = 0;
		}
		
		void Insert(int d)
		{
			if(root == NULL)
			{
				root = new Node(d);
			}
			else
			{
				Node *current = root;
				Node *parent;
				while(current != NULL)
				{
					parent = current;
					if(d < current->data)
					{
						current = current->left;
					}
					else
					{
						current = current->right;
					}
				}
				if(d < parent->data)
				{
					parent->left = new Node(d);
				}
				else
				{
					parent->right = new Node(d);
				}
			}
		}
		
		/*void Inorder_display(Node *r)
		{
			if(r != NULL)
			{
				Inorder_display(r->left);
				cout<<r->data<<" ";
				Inorder_display(r->right);
			}
		}*/
		
		/*void Postorder_display(Node *r)
		{
			if(r != NULL)
			{
				Postorder_display(r->left);
				Postorder_display(r->right);
				cout<<r->data<<" ";
			}
		}*/
		
		/*void Prefix_display(Node *r)
		{
			if(r != NULL)
			{
				cout<<r->data<<" ";
				Prefix_display(r->left);
				Prefix_display(r->right);
			}
		}*/
		
		void input()
		{
			ifstream infile;
			int d;
			infile.open("input3.txt");
			while(!infile.eof())
			{
				infile>>d;
				Insert(d);
			}
		}
		
		int increasing(Node *r)
		{
			if(r == NULL)
			{
				return 0;
			}
			else
			{
				return 1 + increasing(r->right);
			}
		}
		
		int decreasing(Node *r)
		{
			if(r == NULL)
			{
				return 0;
			}
			else
			{
				return 1 + decreasing(r->left);
			}
		}
		
		Node* find_best_root(Node *r)
		{
			if(r == NULL)
			{
				return maxroot;
			}
			else
			{
				if(maxl < decreasing(r) || maxr < increasing(r))
				{
					maxroot = r;
					maxr = increasing(r);
					maxl = decreasing(r);
				}
				find_best_root(r->left);
				find_best_root(r->right);
			}
		}
		
		void write_data(Node *r)
		{
			ofstream outfile;
			outfile.open("output3.txt");
			if(decreasing(root) > decreasing(r) && increasing(root) > increasing(r))
			{
				r = root;
			}
			if(decreasing(r) > increasing(r))
			{
				Node *temp = r;
				outfile<<decreasing(r)<<endl;
				while(temp != NULL)
				{
					outfile<<temp->data<<",";
					temp = temp->left;
				}
			}
			else
			{
				Node *temp = r;
				outfile<<increasing(r)<<endl;
				while(temp != NULL)
				{
					outfile<<temp->data<<",";
					temp = temp->right;
				}
			}
		}
};

int main(void)
{
	BST B;
	B.input();
	Node* A;
	A = B.find_best_root(B.root);
	B.write_data(A);
}
