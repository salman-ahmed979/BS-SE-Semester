#include<iostream>
using namespace std;

class BNode{
	public:
		
		int data;
		BNode *left, *right;
		int height_factor;
		
		BNode() {
			left = 0; right = 0;
		}
		
		BNode(int d) {
			data = d;
			left = 0; right = 0;
			height_factor = 1;
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
		
//		void deleteALL(BNode *&node) {
//			
//			if(node != 0) {
//				deleteAll(node->left);
//				deleteAll(node->right);
//				node->left = 0;
//				node->right = 0;
//				node = 0;
//				delete node;
//			}
//		}
		
		void WipeOut(BNode *&node)
		{
			if(node)
			{
				WipeOut(node->left);
				WipeOut(node->right);
				node->left = 0;
				node->right = 0;
				node = 0;
				delete node;
			}
		}
		
		//Get height factor of a node
		int get_height_factor(BNode *node)
		{
			if(node == 0) return 0;
			return node->height_factor;
		}
		
		//Get the height balance factor
		//Leftsubtree subtract rightsubtree
		int get_Balancefactor(BNode *node)
		{
			if(node == 0) return 0;
			return get_height_factor(node->left) - get_height_factor(node->right);
		}
		
		//Get the max between two nodes height
		int max(int a, int b)
		{
			return (a > b) ? a : b;
		}
		
		//Right Rotate the subtree
		BNode* rightRotation(BNode *y)
		{
			BNode *x = y->left;
			BNode *T2 = x->right;
			
			//Perform Rotation
			x->right = y;
			y->left = T2;
			
			//Adjust the new heights factor
			y->height_factor = 1 + max(get_height_factor(y->left), get_height_factor(y->right));
			x->height_factor = 1 + max(get_height_factor(x->left), get_height_factor(x->right));
			
			return x;
		}
		
		//Left Rotate the subtree
		BNode* leftRotation(BNode *x)
		{
			BNode *y = x->right;
			BNode *T2 = y->left;
			
			//Perform Rotation
			x->left = y;
			y->right = T2;
			
			//Adjust the new heights factor
			x->height_factor = 1 + max(get_height_factor(x->left), get_height_factor(x->right));
			y->height_factor = 1 + max(get_height_factor(y->left), get_height_factor(y->right));
			
			return y;
		}
		
		//Insertion in AVL Tree
		BNode* Insert(BNode *node, int data)
		{
			
			if(node == 0)
			{
				node = new BNode(data);
				return node;
			}
			
			if(node->data > data)
				node->left = Insert(node->left, data);
			else if(node->data < data)
				node->right = Insert(node->right, data);
			
			int balance = get_Balancefactor(node);
			
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
			
			//right left case
			if(balance < -1 && data < node->right->data)
			{
				node->right = rightRotation(node->right);
				return leftRotation(node);
			}
			
			/* return the (unchanged) node pointer */
			return node;
		}
		
		void InsertNode(int d)
		{
			BNode *temp;
			if(root == 0)
			{
				temp = new BNode(d);
				root = temp;
				return;
			}
			temp = root;
			BNode *t = Insert(temp, d);
			//t = 0;
			//delete t;
		}
		
		void InOrder(BNode *p)
        {
            if(p != 0) {
                InOrder(p->left);
                cout << p->data << " ";
                InOrder(p->right);
            }
        }
        
        void InOrder_Traversal(void) {
            BNode *current = root;
            InOrder(current);
            current = 0; 
            delete current;
        }
		
		~AVLTree()
		{
			if(root)
			{
				WipeOut(root);
			}
		}
};
int main()
{
	AVLTree t1;
	t1.InsertNode(5);
	t1.InsertNode(4);
	t1.InsertNode(1);
	t1.InOrder_Traversal();
	//t1.
	return 0;
}
