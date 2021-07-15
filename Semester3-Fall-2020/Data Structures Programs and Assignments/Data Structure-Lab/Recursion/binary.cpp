#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};
class BinaryTree
{
    private:
        Node *root;
    public:
        BinaryTree()
        {
            this->root = 0;
        }

        void Insert(int data)
        {
            Node *temp = new Node;
            temp->data = data;
            temp->left = 0; temp->right = 0;
            if(root == 0)
            {
                root = temp;
            }
            else {
                Node *current = root;
                Node *prev = 0;
                while(current != 0)
                {
                    prev = current;
                    if(current->data > data)
                        current = current->left;
                    else
                        current = current->right;
                    
                }
                if(prev->data > data)
                    prev->left  = temp;
                else
                {
                    prev->right = temp;
                }
            }
            delete temp;
        }

        void Print(void)
        {
            Node *temp  = root;
            InOrder(temp);
            delete temp;
        }
        void InOrder(Node *p)
        {
            if(p == 0) return;
            InOrder(p->left);
            cout << p->data << " ";
            InOrder(p->right);
        }
        void deleteN(Node *&p)
        {
            deleteN(p->left);
            deleteN(p->right);
            delete p;
        }
        ~BinaryTree()
        {
            deleteN(root);
        }

};
int main()
{
    cout << "Hello Salman";
    BinaryTree b1;
    b1.Insert(5);
    b1.Insert(19);
    b1.Insert(3);
    b1.Print();
    return 0;
}