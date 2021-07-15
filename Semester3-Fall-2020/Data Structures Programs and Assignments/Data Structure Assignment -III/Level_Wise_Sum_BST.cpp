#include<iostream>
#include<queue>
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
		
		int max(int a, int b)
		{
			if(a > b)return a;
			return b;
		}
		//Calculate the height of tree
		int height(BNode *p)
		{
			if(p == 0)return 0;
			
			return 1 + max(height(p->left), height(p->right));
			
		}
		
		int get_two_power(int n)
		{
			if(n == 0) return 1;
			int mul = 1;
			for(int i=1; i<=n; i++)
				mul *= 2;
			return mul;
		}
		
		//Finding level wise Sum
		void Level_Wise_Sum(void) {
			
			BNode *current = root;
			queue<BNode *> q1;
			q1.push(current);
			int heightt = height(current);
			int n = 0;
			while( !q1.empty() )
			{
				int sum = 0;
				int queue_size = q1.size();
				
				int get_multiply = get_two_power(n);
				//cout << "\nMultiply factor: "<<get_multiply <<"\n";
				while( queue_size <= get_multiply)
				{
					if(queue_size > 0){
					//cout << "\nQueue size: " << queue_size << "\n";
					BNode *temp = q1.front();
					sum += temp->Data;
					//cout << "\nSum: "<< sum << "\n";
					if(temp->left != 0)
						q1.push(temp->left);
					if(temp->right != 0)
						q1.push(temp->right);
					
					q1.pop();
					queue_size--;}
					else break;
					
				}
				//cout << "\nSize of Queue: " << queue_size << "\n";
				if(n == heightt || q1.empty())
					cout << sum;
				else cout << sum << "-";
				n++;
			}
		}
};
int main(){
	
	BSTree b1;
    b1.InsertNode(34);
    b1.InsertNode(29);
    b1.InsertNode(65);
    b1.InsertNode(21);
    b1.InsertNode(31);
    b1.InsertNode(43);
    b1.InsertNode(87);
    b1.InsertNode(56);
    b1.InsertNode(28);
    b1.InsertNode(30);
    b1.Level_Wise_Sum();
	
	return 0;
}
