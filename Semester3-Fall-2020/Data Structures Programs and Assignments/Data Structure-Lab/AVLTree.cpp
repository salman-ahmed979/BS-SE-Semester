#include<iostream>
using namespace std;
class BNode{
	public:
		int data;
		int balancefactor;
		BNode *left, *right;
	
		BNode(int data)
		{
			this->data = data;
			balancefactor = 1;
			left = 0; right = 0;
		}
		BNode(){
			data  = 0;
			balancefactor = 0;
			left = 0;
			right = 0;
		}
};
class AVLTree{
	private:
		BNode *root;
	public:
		AVLTree()
		{
			root = 0;
		}
		
		int getBalance(BNode *temp)
		{
			if(temp == 0) return 0;
			return height(temp->left) - height(temp->right);
		}
		
		int height(BNode *temp)
		{
			if(temp == 0) return 0;
			return temp->balancefactor;
		}
		
		int max(int a, int b)
		{
			return (a > b) ? a : b;
		}
		
		//Rotate the subtree of y
		BNode* rightRotation(BNode *y)
		{
			BNode *x = y->left;
			BNode *T2 = x->right;
			
			//Perform Rotation
			x->right = y;
			y->left = T2;
			
			//Update heights
			y->balancefactor = max(height(y->left), height(y->right)) + 1;
			x->balancefactor = max(height(x->left), height(x->right)) + 1;
			
			return x;
		}
		
		//Rotate the subtree of x
		BNode* leftRotation(BNode *x)
		{
			BNode *y = x->right;
			BNode *T2 = y->left;
			
			//Perform rotation
			y->left = x;
			x->right = T2;
			
			//Update heights
			x->balancefactor = max(height(x->left), height(x->right)) + 1;
			y->balancefactor = max(height(y->left), height(y->right)) + 1;
			
			return y;
		}
		
		void Insert(BNode *node, int data)
		{
			if(node == 0)
			{
				node = new BNode(data);
				return node;
			}
			if(node->data > data)
				node->left = Insert(node->left, data);
			else if (node->data < data)
				node->right = Insert(node->right, data);
			
			node->balancefactor = 1 + max(height(node->left), height(node->right));
			
			int balance = getBalance(node);
			
			//left left case
			if(balance > 1 && data < node->left->data)
				return rightRotation(node);
			
			//right right case
			if(balance < -1 && data > node->right->data)
				return leftRotation(node);
				
			//left right case
			if(balance > 1 && data > node->left->data)
			{
				node->left = leftRotation(node->left);
				return rightRotation(node);
			}
			
			// Right Left Case  
   			if (balance < -1 && data < node->right->data)  
    		{  
        		node->right = rightRotate(node->right);  
        		return leftRotate(node);  
    		}  
 	 
   			 /* return the (unchanged) node pointer */
   			 return node;
		}
};

