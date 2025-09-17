#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
}*Root;

class BST{
	public:
		BST(){
			Root = NULL;
		}
		
	void insert(node* q, node* newNode){
		if(Root == NULL){
			Root = new node;
			Root->data = newNode->data;
			Root->left = NULL;
			Root->right = NULL;
			cout<<"\nRoot node is added..."<<endl;
			return;
		}
		
		if(q->data == newNode->data){
			cout<<"\nNode allready exist..."<<endl;
			return;
		}
		
		if(q->data > newNode->data){
			if(q->left != NULL){
				insert(q->left , newNode);
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
				q->right->left = NULL;
				q->right->right = NULL;
				return;
			}
		}
	}
	
	
	void preOrder(node* q){
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
	
	void inOrder(node* q){
		if(Root == NULL){
			cout<<"\nTree is empty..."<<endl;
			return;
		}
		if(q != NULL){
			inOrder(q->left);
			cout<<q->data<<",";
			inOrder(q->right);
		}
	}
	
	void postOrder(node* q){
		if(Root == NULL){
			cout<<"\nTree is empty..."<<endl;
			return;
		}
		if(q != NULL){
			inOrder(q->right);
			inOrder(q->left);
			cout<<q->data<<",";
		}
	}
	
	void display(node *q, int level)
	{
		int i;
		if (q != NULL){
			display(q->right, level + 1);
			cout << endl;
			if (q == Root)
				cout << "Root->: ";
			else{
				for (i = 0; i < level; i++)
				cout << " ";
			}
			cout << q->data;
			display(q->left, level + 1);
		}
	}
	
};


int main(){
	BST t;
	for(int i=20; i>=1; i--){
		node* r = new node;
		r->data = i;
		t.insert(Root, r);
	}
	
	for(int i=21; i<=40; i++ ){
		node* r = new node;
		r->data = i;
		t.insert(Root, r);
	}
	
	t.preOrder(Root);
	cout<<endl;
	t.inOrder(Root);
	cout<<endl;
	t.postOrder(Root);
	cout<<endl;
	t.display(Root, 0);
	
	return 0;
}
