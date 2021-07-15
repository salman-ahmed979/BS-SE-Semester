#include<iostream>
#include<queue>
using namespace std;

struct BSTNode{
	int Data; 
	BSTNode *left, *right;
};
class BSTree
{
	private:
		BSTNode *root;
	public:
		static int count;
		BSTree()
		{
			root = 0;	
		}	
		
		void Insert_Node(int data) 
		{
			BSTNode *temp = new BSTNode;
			temp->Data = data;
			temp->left = 0; temp->right = 0;
			
			if(root == 0) {
				root = temp; cout << "\nHere\n";
			}
			else {
				BSTNode *current = root;
				BSTNode *trail_current = 0;
				
				while(current != 0)
				{
					if(current->Data == temp->Data)
					{
						cout << "\nAlready Exist\n"; return;
					}
					trail_current = current;
					if(current->Data > temp->Data)
						current = current->left;
					else if(current->Data < temp->Data)
						current = current->right;
				}
				if(trail_current->Data > temp->Data)
					trail_current->left = temp;
				else
					trail_current->right = temp;
					
				temp = 0; trail_current = temp; delete temp; delete current; delete trail_current;
			}
			cout << "\nInsertion Success\n";
		}
		
		//Traversal Using Depth search traverse
		
		//Inorder Traversal : L n R
		void Inorder_Traverse(BSTNode *&node)
		{
			if(node != 0)
			{
				Inorder_Traverse(node->left);
				cout << node->Data << " ";
				Inorder_Traverse(node->right);
			}
		}
		
		//Pre-Order Traverse : n L R 
		void PreOrder_Traverse(BSTNode *&node)
		{
			if(node != 0)
			{
				cout << node->Data << " ";
				PreOrder_Traverse(node->left);
				PreOrder_Traverse(node->right);
			}
		}
		
		//Post-Order Traverse : L R n
		void PostOrder_Traverse(BSTNode *&node)
		{
			if(node != 0)
			{
				PostOrder_Traverse(node->left);
				PostOrder_Traverse(node->right);
				cout << node->Data << " ";
			}
		}
		
		void Breadth_First_Traversal(BSTNode *node)
		{
			queue<BSTNode *> q1;
			BSTNode	*p = node;
			if(p != 0)
			{
				q1.push(p);
				while( !q1.empty() )
				{
					p = q1.front();
					q1.pop();
					cout << p->Data << " ";
					if(p->left != 0)
						q1.push(p->left);
					if(p->right != 0)
						q1.push(p->right);
				}
			}
		}
		
		void DeleteByMerge(BSTNode *&node)
		{
			BSTNode *temp = node;
			if(node != 0)
			{
				if(node->left == 0)
					node = node->right;
				else if(node->right == 0)
					node = node->left;
				else
				{
					temp = node->left;
					while(temp->right != 0)
						temp = temp->right;
					
					temp->right = node->right;
					temp = node;
					node = node->left;
				}
			}
			delete temp;
		}
		
		void Delete_ByFinding_Merge(int data)
		{
			BSTNode *node = root, *prev = 0;
			while(node != 0)
			{
				if(node->Data == data)
					break;
				prev = node;
				if(node->Data > data)
					node = node->left;
				else if(node->Data < data)
					node = node->right;
			}
			if(node != 0 && node->Data == data)
			{
				if(node == root)
					DeleteByMerge(root);
				else if(prev->left == node)
					DeleteByMerge(prev->left);
				else if(prev->right == node)
					DeleteByMerge(prev->right);
			}
		}
		
		void Delete_ByCopy(BSTNode *&node)
		{
			BSTNode *prev = 0, *temp = node;
			if(node->right == 0)
				node = node->left;
			else if(node->left == 0)
				node = node->right;
			else
			{
				temp = node->left;
				while(temp->right != 0)
				{
					prev = temp;
					temp = temp->right;
				}
				if(prev == node)
					prev->left = temp->left;
				else
					prev->right = temp->left;
			}
			temp = 0;
			delete temp;
		}
		
		void Copy_tree(BSTNode *&copy, BSTNode *&other)
		{
			if(other == 0)
				copy  = 0;
			else {
				copy = new BSTNode ;
				copy->Data = other->Data;
				Copy_tree(copy->left, other->left);
				Copy_tree(copy->right, other->right);
			}
		}
		void Traverse(void) {
			//Inorder_Traverse(root);
			//PreOrder_Traverse(root);
			Breadth_First_Traversal(root);
			cout << "\nCount: " << Count_AllNodes(root) << "\n";
						
		}
		
		int Count_leaves(BSTNode *&node)
		{
			if(node == 0) return 0;
			
			else if(node->left == 0 && node->right == 0) return 1;	
			
			else
				return Count_leaves(node->left) + Count_leaves(node->right);
		}
		
		int Count_AllNodes(BSTNode *&node)
		{
			if(node == 0) return 0;
			int res = 1;
			res += Count_AllNodes(node->left) + Count_AllNodes(node->right);
			return res;
		}
		
		void Delete_AllNode(BSTNode *&node)
		{
			if(node) {
				Delete_AllNode(node->left);
				Delete_AllNode(node->right);
				delete node;
			}
		}
		~BSTree() 
		{
			Delete_AllNode(root);
		}
		
		void Copy_Tree_Node(BSTNode *copy, BSTNode *other)
		{
			if(other == 0)
				copy = 0;
			else
			{
				copy = new BSTNode;
				copy->Data = other->Data;
				Copy_Tree_Node(copy->left, other->left);
				Copy_Tree_Node(copy->right, other->right);
			}
		}
};
int BSTree::count = 0;
int main()
{
	BSTree b1;
	b1.Insert_Node(4);
	b1.Insert_Node(5);
	b1.Insert_Node(1);
	b1.Traverse();
	b1.Delete_ByFinding_Merge(4);
	b1.Traverse();
	return 0;
}
