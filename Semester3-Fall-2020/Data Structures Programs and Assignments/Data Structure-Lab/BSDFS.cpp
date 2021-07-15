#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

struct BNode{
	int Data;
	BNode *left, *right;
};
class BSTree{
	private:
		BNode *root;
	public:
		//Default Constructor
		BSTree() {
			root = 0;
		}
		
		//Insert a Node
		void InsertNode(int data) {
			
			//Create a node
			BNode *node = new BNode;
			node->Data = data;
			node->left = 0;
			node->right = 0;
			
			//Check whether tree is empty
			if(root == 0)
			{
				root = node;
			}
			else {
				BNode *current = root;
				BNode *previous = 0;
				
				while(current != 0)
				{
					previous = current;
					if(current->Data == node->Data) return;
					
					if(current->Data > node->Data)
						current = current->left;
					else
						current = current->right;
				}
				
				if(previous->Data > node->Data)
					previous->left = node;
				else
					previous->right = node;
				
				previous = 0; delete previous; 
				delete current; 
				node = 0; delete node;
			}
		}
		
		void InOrder(BNode *p)
		{
			if(p != 0) {
				InOrder(p->left);
				cout << p->Data << " ";
				InOrder(p->right);
			}
		}
		
		void InOrder_Traversal(void) {
			BNode *current = root;
			InOrder(current);
			current = 0; 
			delete current;
		}
		
		void DeleteAll(BNode *&p) {
			if(p)
			{
				DeleteAll(p->left);
				DeleteAll(p->right);
				p->left = 0;
				p->right = 0;
				p = 0;
				delete p;
			}
		}
		
		~BSTree()
		{
			if(root)
			{
				DeleteAll(root);
			}
		}
		
		void Breadth_First_Search(int d)
		{
			BNode *temp = root;
			queue<BNode *> q1;
			q1.push(temp);
			while( !q1.empty())
			{
				BNode *current = q1.front();
				q1.pop();
				if(current->Data == d) {cout << "Found Data: " << current->Data; break;}
				if(temp->left != 0)
					q1.push(temp->left);
				if(temp->right != 0)
					q1.push(temp->right);
				current = 0; delete current;
			}
			if( !q1.empty())
			{
				cout << "\nSuccess\n";
				while(!q1.empty())
				{
					q1.pop();
				}
			}
			temp = 0; delete temp;
		}
		
		void Depth_Search(int d)
		{
			BNode *temp = root;
			stack<BNode *> s1;
			s1.push(temp);
			while( !s1.empty())
			{
				BNode *current = s1.top();
				s1.pop();
				if(current->Data == d) {cout << "Found Data: " << current->Data; break;}
				if(temp->left != 0)
					s1.push(temp->left);
				if(temp->right != 0)
					s1.push(temp->right);
				current = 0; delete current;
			}
			if( !s1.empty())
			{
				cout << "\nSuccess\n";
				while(!s1.empty())
				{
					s1.pop();
					//= 0; delete c;
				}
			
			}
			temp = 0; delete temp;	
		}

		//Lowest Common Ancestor
		int LCA(BNode *p, int key1, int key2);
};
int main()
{
	BSTree b1;
	b1.InsertNode(5);
	b1.InsertNode(6);
	b1.InsertNode(4);
	b1.InsertNode(3);
	b1.InOrder_Traversal();
	b1.Breadth_First_Search(3);
	b1.Depth_Search(6);
	return 0;
}
