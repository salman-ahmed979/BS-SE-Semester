#include<bits/stdc++.h>
using namespace std;
struct BNode{
	int data;
	BNode *left, *right;
};
class BSTree{
	private:
		BNode *root;
	public:
		BSTree()
		{
			root = 0;
		}
		
		void AddNode(int data)
		{
			//Create a Node
			BNode *temp = new BNode;
			temp->data = data;
			temp->left = 0; temp->right = 0;
			
			//If tree is empty, insert there
			if(root == 0)
			{
				root = temp;
			}
			else {
				BNode *current = root;
				BNode *previous = 0;
				
				while(current != 0)
				{
					previous = current;
					//If Node data is same as the coming data
					if(current->data == data) return;
					
					if(current->data > data)
						current = current->left;
					else
						current = current->right;					
				}		
				if(previous->data > data) {
					previous->left = temp;
					previous = temp;
				}		
				else {
					previous->right = temp;
					previous = temp;
				}
				previous = 0; current = 0;
				delete previous; delete current;
			}
			temp = 0;
			delete temp; 
		}
		
		BNode* get_Node(int data)
		{
			BNode *current = root;
			while(current != 0)
			{
				if(current->data == data)
					break;
				if(current->data > data)
					current = current->left;
				else
					current = current->right;
			}
			return current;
		}
		
		void Search(int data)
		{
			BNode *value = get_Node(data);
			if(value->data == data)
			{
				cout << "\nNode Address: " << value << "\nValue: " << value->data;
			}
			else{
				cout << "\nNot Found";
			}
			value = 0;
			delete value;
		}
		
		void InOrder(BNode *&current)
		{
			if(current == 0) return;
			InOrder(current->left);
			cout << current->data << " ";
			InOrder(current->right);
		}
		
		void PreOrder(BNode *&current)
		{
			if(current == 0) return;
			cout << current->data << " ";
			PreOrder(current->left);
			PreOrder(current->right);
		}
		
		void PostOrder(BNode *&current)
		{
			if(current == 0) return;
			PostOrder(current->left);
			PostOrder(current->right);
			cout << current->data << " ";
		}
		
		void Traversal_PreOrder(void)
		{
			BNode *current = root;
			PreOrder(current);
			current = 0;
			delete current;
		}
		
		void Traversal_InOrder(void)
		{
			BNode *current = root;
			InOrder(current);
			current = 0;
			delete current;
		}
		
		void Traversal_PostOrder(void)
		{
			BNode *current = root;
			PostOrder(current);
			current = 0;
			delete current;
		}
		
		void InOrder_Iterative(void)
		{
			stack<BNode *> s;
			BNode *current = root;
			while( !s.empty() || current!=0)
			{
				if(current != 0)
				{
					s.push(current);
					current = current->left;
				}
				else
				{
					current = s.top();
					s.pop();
					cout << current->data << " ";
					current = current->right;
				}
			}
			current = 0;
			delete current;
		}
		
		void PreOrder_Iterative(void)
		{
			BNode *current = root;
			if(current == 0) return;
			
			stack<BNode *> s;
			s.push(current);
			while(!s.empty())
			{
				current = s.top();
				s.pop();
				cout << current->data << " ";
				if(current->right != 0)
					s.push(current->right);
				if(current->left != 0)
					s.push(current->left);
			}
		}
		
		void PostOrder_Iterative(void)
		{
			stack<BNode *>s;
			stack<BNode *>t;
			BNode *current = root;
			s.push(current);
			while(!s.empty())
			{
				current = s.top();
				s.pop();
				
				t.push(current);
				if(current->left != 0)
					s.push(current->left);
				if(current->right != 0)
					s.push(current->right);
			}
			while(!t.empty())
			{
				current = t.top();
				t.pop();
				cout << current->data << " ";
			}
			current = 0; delete current;
		}
		
		void Delete(BNode *&current) {
			if(current != 0)
			{
				Delete(current->left);
				Delete(current->right);
				current->left = 0;
				current->right = 0;
				
				delete current;
			}
		}
		~BSTree()
		{
			Delete(root);
		}
};
int main()
{
	BSTree b1;
	b1.AddNode(5);
	b1.AddNode(4);
	b1.AddNode(6);
	b1.Traversal_InOrder();
	cout << "\nIterative InOrder: ";
	b1.InOrder_Iterative();
	cout << "\nPreOrder Iterative: ";
	b1.PreOrder_Iterative();
	cout << "\nPostOrder Iterative: ";
	b1.PostOrder_Iterative();
	return 0;
}
