#include <bits/stdc++.h>
using namespace std;

class BNode {
    public:
        int data;
        BNode *left, *right;

        BNode() {
            data = 0; left = 0; right = 0;
        }

        BNode(int d) {
            data = d;
            left = 0; right = 0;
        }
};
class BST {
    BNode *root;
    public:
        BST() {
            root = 0;
        }
        void Ins (BNode *&current, BNode *&node) {
            if(current == 0)
            {
                current = node;
                node = 0;
                return;
            }
            if (current->data > node->data)
                Ins(current->left, node);
            else if(current->data < node->data)
                Ins(current->right, node);
        }

        void Insert (int d) {
            BNode *temp = new BNode(d);
            BNode *current = root;
            Ins(current,temp);
            temp = 0; current = 0;
            delete temp; delete current;
        }

        void Inorder(BNode *&current) {
            if(current != 0) {
               cout << "\n\n" <<  current->left->data << " " << current->data << " " << current->right->data;
            }
        }

        void IO(){
            BNode *current = root;
            Inorder(current);
            current = 0;
        }
        void WipeOut(BNode *&node)
         {
             if(node){
                 WipeOut(node->left);
				WipeOut(node->right);
				node->left = 0;
				node->right = 0;
				node = 0;
				delete node;
             }
         }
        ~BST() {
            if(root)
                WipeOut(root);
        }
};
int main() {
    BST b1;
    b1.Insert(10);
    b1.Insert(5);
    b1.Insert(20);
    b1.IO();
    return 0;
}
