#include<iostream>
using namespace std;

template <class T>
class Stack;
template <class T>
class Queue;
template <class T>
class BinarySearchTree;

template <class T>
class Stack_Node {
	private:
		T data;
		Stack_Node<T>* next;
	public:
		Stack_Node();
		Stack_Node(T);	
		friend class Stack<T>;
};
template<class T>
Stack_Node<T>::Stack_Node(){
	data=0;
	next=NULL;
}
template<class T>
Stack_Node<T>::Stack_Node(T d){
	data=d;
	next=NULL;
}

template <class T>
class Stack {
	private:
		Stack_Node<T>* Top;
	public:
		Stack();
		void push(T);
		T pop();
		T peek() const;
		bool IsEmpty() const;
		~Stack();
};
template <class T>
Stack<T>::Stack(){
	Top=NULL;
}
template <class T>
bool Stack<T>::IsEmpty() const{
	if (Top==NULL){
		return true;
	}
	return false;
}
template <class T>
void Stack<T>::push(T d){
	Stack_Node<T>* createNode = new Stack_Node<T>(d);
	if (IsEmpty()){
		Top = createNode;
	}
	else {
		createNode->next = Top;
		Top = createNode;
	}
}
template <class T>
T Stack<T>::pop(){
	if(IsEmpty()){
		return NULL;
	}
	else {
		T value = Top->data;
		Stack_Node<T>* temp=Top;
		Top=Top->next;
		delete temp;
		return value;
	}
}
template<class T>
T Stack<T>::peek() const{
	if (IsEmpty()){
		return -1;
	}
	else {
		return Top->data;
	}
}
template <class T>
Stack<T>::~Stack(){
	if (Top!=NULL){
		delete Top;
		Top = NULL;
	}
}

template <class T>
class Queue_Node{
	private:
		T data;
		Queue_Node<T>* next;
	public:
		Queue_Node();
		Queue_Node(T);
		friend class Queue<T>;
};
template <class T>
Queue_Node<T>::Queue_Node(){
	data = 0;
	next = NULL;
}
template <class T>
Queue_Node<T>::Queue_Node(T d){
	data = d;
	next = NULL;
}

template <class T>
class Queue{
	private:
		Queue_Node<T>* Front;
		Queue_Node<T>* Rear;
	public:
		Queue();
		void Enqueue(T);
		T Dequeue();
		T getFrontEl() const;
		T getRearEl() const;
		bool IsEmpty() const;
		~Queue();
};
template<class T>
Queue<T>::Queue(){
	Front = NULL;
	Rear = NULL;
}
template <class T>
bool Queue<T>::IsEmpty() const{
	if (Front==NULL && Rear==NULL)
		return true;
	return false;
}
template <class T>
Queue<T>::~Queue(){
	if (Front!=NULL && Rear!=NULL){
		delete Front;
		delete Rear;
		Front=NULL;
		Rear=NULL;
	}
}
template<class T>
void Queue<T>::Enqueue(T d){
	Queue_Node<T>* createNode = new Queue_Node<T>(d);
	if (IsEmpty()){
		Rear=createNode;
		Front= createNode;
	}
	else{
		Rear->next = createNode;
		Rear = Rear->next;
	}
}
template <class T>
T Queue<T>::Dequeue(){
	if (IsEmpty()){
		return NULL;
	}
	else {
		T value = Front->data;
		Queue_Node<T>* temp=Front;
		Front=Front->next;
		
		return value;
	}
}
template <class T>
T Queue<T>::getFrontEl() const{
	if (IsEmpty()){
		return -1;
	}
	return Front->data;
}
template <class T>
T Queue<T>::getRearEl() const{
	if (IsEmpty()){
		return -1;
	}
	return Rear->data;
}

template <class T>
class BSTNode{
	private:
		T data;
		BSTNode* left;
		BSTNode* right;
	public:
		BSTNode();
		BSTNode(T d);
		friend class BinarySearchTree<T>;
};
template <class T>
BSTNode<T>::BSTNode(){
	data = 0;
	left = NULL;
	right = NULL;
}
template <class T>
BSTNode<T>::BSTNode(T d){
	data = d;
	left = NULL;
	right = NULL;
}


template <class T>
class BinarySearchTree {
	private:
		BSTNode<T>* root;
		void deleteRecursively(BSTNode<T>*);
	public:
		BinarySearchTree();
		BSTNode<T>* getRoot() const;
		void Insert_Node(BSTNode<T>*&,T);
		void Inorder(BSTNode<T>*);
		BSTNode<T>* DeleteNode(BSTNode<T>*,T);
		BSTNode<T>* minNodeValue(BSTNode<T>*);
		bool Depth_FirstSearch(BSTNode<T>*,T);
		bool Breadth_FirstSearch(BSTNode<T>*,T);
		~BinarySearchTree();
};
template <class T>
void BinarySearchTree<T>::deleteRecursively(BSTNode<T> *r){
	if (r){
		deleteRecursively(r->left);
		deleteRecursively(r->right);
		delete r;
	}
}
template <class T>
BinarySearchTree<T>::BinarySearchTree(){
	root = NULL;
}
template <class T>
BinarySearchTree<T>::~BinarySearchTree(){
	deleteRecursively(root);
}
template <class T>
BSTNode<T>* BinarySearchTree<T>::getRoot() const{
	return root;
}

template <class T>
void BinarySearchTree<T>::Inorder(BSTNode<T> *r){
	if (r){
		Inorder(r->left);
		cout<<r->data<<" ";
		Inorder(r->right);
	}
}
template <class T>
bool BinarySearchTree<T>::Depth_FirstSearch(BSTNode<T>* r,T d){
	if (r==NULL)
		return 0;
	Stack<BSTNode<T>*> S;
	S.push(r);
	while(!S.IsEmpty()){
		BSTNode<T> *x=S.pop();
	
		if (x->data==d)	return true;
		if (x->left!=NULL) S.push(x->left);
		if (x->right!=NULL)	S.push(x->right);
	}
	return false;
}
template <class T>
bool BinarySearchTree<T>::Breadth_FirstSearch(BSTNode<T>* r,T d){
	if (r==NULL){
		return 0;
	}
	Queue<BSTNode<T>*> Q;
	Q.Enqueue(r);
	while(!Q.IsEmpty()){
		BSTNode<T>* y=Q.Dequeue();
	
		if (y->data==d) return true;
		if (y->left!=NULL)	Q.Enqueue(y->left);
		if (y->right!=NULL) Q.Enqueue(y->right);
	}
	return false;
}
template <class T>
BSTNode<T>* BinarySearchTree<T>::minNodeValue(BSTNode<T>* r){
	BSTNode<T>* curr=r;
	while(curr->left!=NULL){
		curr=curr->left;
	}
	return curr;
}
template <class T>
BSTNode<T>* BinarySearchTree<T>::DeleteNode(BSTNode<T>*r,T d){
	if (r==NULL){
		return NULL;
	}
	else if (d<r->data){
		r->left = DeleteNode(r->left,d);
	}
	else if (d>r->data){
		r->right = DeleteNode(r->right,d);
	}
	else {
		if (r->left==NULL){
			BSTNode<T>* temp = r->right;
			delete r;
			return temp;
		}
		else if (r->right==NULL){
			BSTNode<T>* temp = r->left;
			delete r;
			return temp;
		}
		else {
			BSTNode<T>* temp = minNodeValue(r->right);
			r->data = temp->data;
			r->right=DeleteNode(r->right,d);
		}
	}
	return r;
}
template <class T>
void BinarySearchTree<T>::Insert_Node(BSTNode<T>*& r,T d){
	BSTNode<T>* create_node = new BSTNode<T>(d);
	if (r==NULL){
		r=create_node;
		return;
	}
	else if (d<r->data){
		Insert_Node(r->left,d);
	}
	else {
		Insert_Node(r->right,d);
	}
}


int main(){
	BinarySearchTree<int> tree;
	BSTNode<int> *r = tree.getRoot();
	int option,d;
    do {
        cout<<"What Operation do you want to perform?"
        <<"Opt option Number. "<<endl<<"Enter 0 to Exit." <<endl;
        cout<<"[1] Insert Node"<<endl;
        cout<<"[2] Depth For Search"<<endl;
        cout<<"[3] Breadth For Search"<<endl;
        cout<<"[4] Print BST values "<<endl;
        cout<<"[5] Delete Node In BST"<<endl;
        cout<<"[5] Clear Screen"<<endl;
        cout<<"[0] Exit Application"<<endl;
        cin>>option;

        switch(option){
            case 0:
                break;
            case 1:
                cout<<"INSERT"<<endl;
              	cout<<"Enter the Value to Insert\n";
				cin>>d;
				tree.Insert_Node(r,d);
                break;
            case 2:
            	cout<<"DEPTH FOR SEARCH IN BST"<<endl;
            	cout<<"Enter the Value to Search\n";
				cin>>d;
				cout<<tree.Depth_FirstSearch(r,d);
                break;
            case 3:
            	cout<<"BREADTH FOR SEARCH IN BST"<<endl;
            	cout<<"Enter the Value to Search\n";
				cin>>d;
				cout<<tree.Breadth_FirstSearch(r,d);
               	break;
            case 4:
                cout<<"PRINT and TRAVERSE"<<endl;
                tree.Inorder(r);
                break;
            case 5:
            	cout<<"DElETION OF NODE IN BST"<<endl;
            	cout<<"Enter the Value to Delete\n";
				cin>>d;
            	r=tree.DeleteNode(r,d);
				break;
            case 6:
                system("cls");
                break;
            default:
                cout<<"Invalid Input"<<endl;
                break;
        }
        
    }while(option!=0);
    
    return 0;
}
