#include<iostream>
using namespace std;

class Stack{
	struct node{
		int data;
		node *link;
	}*p;
	
	public:
		void push(char);
		void pop();
		void display();
		
	Stack(){
		p = NULL;
	}
		
};

void Stack::push(char x){
	node * q;
	q = new node;
	q->data = x;
	q->link = NULL;
	
	if(p == NULL){
		p = q;
	}
	else{
		q->link = p;
		p = q;
	}
}

void Stack::pop(){
	if(p == NULL){
		cout<<"\nStack is empty...\n";
		return;
	}
	
	node *q;
	q = p;
	p = p->link;
	delete q;
	
}

void Stack::display(){
	if(p == NULL){
		cout<<"\nStack is empty...."<<endl;
		return;
	}
	node *q = p;
	
	while (q != NULL){
		cout<<endl<<q->data;
		q = q->link;
	}
	return;
	
}


int main(){
	Stack st;
	st.display();
	
	
	return 0;
}