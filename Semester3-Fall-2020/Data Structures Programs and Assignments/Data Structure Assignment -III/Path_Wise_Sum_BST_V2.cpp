#include <map>
#include <set>
#include <list>
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
    static int path_tracker;
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
        
       void PathWise_Sum(void) {
            int sum = 0;
            BNode *current = root;
            int leaves = this->Count_leaves(current);
            
            if( current->left == 0 && current->right == 0 ) cout << current->Data;
            
            else if(leaves == 0) cout << 0;
            
            else
                Pathwise(current, sum, leaves);
            current = 0; delete current;
        }
        
        void Pathwise(BNode *current, int sum, int leaves) {
            if(current == 0) {
                return;
            }
            
            sum += current->Data;
            Pathwise(current->left, sum, leaves);
            Pathwise(current->right, sum, leaves);
            
            if(current->left == 0 && current->right == 0 && current != root) {
                path_tracker++;
                if(path_tracker == leaves) cout << sum;
            
                else
                    cout << sum << "-";
            }
        }
        
        //Counting leaves of binary search tree
        int Count_leaves(BNode *p) {
            if(p == 0) return 0;
            else if (p->left == 0 && p->right == 0) return 1;
            return Count_leaves(p->left) + Count_leaves(p->right);
        }
        
        //Itrative Function
        void PathWise_Sum_Calculate(void) {
            
            BNode *current = root;
            int leaves = Count_leaves(current);
            int track_leaves = 0;
            cout << leaves;
            //Create a Stack of Nodes
            stack<BNode *>s1;
            
            while(track_leaves <= leaves)
            {
                int sum = 0;
                while(current != 0) {
                    if(s1.empty() || s1.top() != current)
                        s1.push(current);
                    sum += current->Data;
                    if(current->left != 0)
                        current = current->left;
                    else if(current->right != 0)
                        current = current->right;
                }
                
                track_leaves++;
                if(track_leaves == leaves) cout << sum;
                else cout << sum << "-";
                
                //remaining work
                s1.pop();
                current = s1.top();
            }   
            while(!s1.empty()) {
                s1.pop();
            }
        }
};
int BSTree::path_tracker=0;
int main() {
    BSTree b1;
    string str[50];
    int i = 0;
    cin >> str[i];
    while(str[i] != "")
    {
        int num = stoi(str[i]);
        b1.InsertNode(num);
        i++;
        cin >> str[i];        
    }
    b1.PathWise_Sum();
    return 0;
}
