#include<iostream>
using namespace std;

struct node{
		int data;
		node *left;
		node *right;
	};
	
class Tree{
	public:
		void insert(node*, node*);
		void preOrder(node*);
		void invertTree(node*);
		
	node * Root;	
	Tree(){
		Root = NULL;
	}
	
};

void Tree::insert(node *q, node *newNode){
	if(Root == NULL){
		Root = new node;
		Root->data = newNode->data;
		Root->left = NULL;
		Root->right = NULL;
		return;
	}
	if(q->data == newNode->data){
		cout<<newNode->data<<" Can't be inserted .... Already exist...\n";
		return;
	}
	if(newNode->data < q->data){
		if(q->left != NULL){
			insert(q->left, newNode);
		}
		else{
			q->left = newNode;
			q->left->left = NULL;
			q->left->right = NULL;
			return;
		}
	}
	else{
		if(q->right != NULL){
			insert(q->right, newNode);
		}
		else{
			q->right = newNode;
			q->right->right = NULL;
			q->right->left = NULL;
			return;
		}
	}
	
}

void Tree::preOrder(node *q){
	if(Root == NULL){
		cout<<"\nTree is empty..."<<endl;
		return;
	}
	if(q != NULL){
		cout<<q->data<<",";
		preOrder(q->left);
		preOrder(q->right);
	}
}

void Tree::invertTree(node* q){
	if(Root == NULL){
		cout<<"Tree is empty...."<<endl;
		return;
	}
	
	node* temp = q->left;
	q->left = q->right;
	q->right = temp;
	
	if(q->right != NULL)
	invertTree(q->right);
	if(q->left != NULL)
	invertTree(q->left);
	
}

int main(){
	Tree t;
	t.preOrder(t.Root);
	for(int i=0; i<=10; i++){
		node *r = new node;
		r->data = i;
		t.insert(t.Root, r);
	}
	
	t.preOrder(t.Root);
	cout<<endl;
	
	t.invertTree(t.Root);
	
	t.preOrder(t.Root);
	
	return 0;
	
}