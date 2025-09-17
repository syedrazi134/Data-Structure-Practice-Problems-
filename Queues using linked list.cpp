#include<iostream>
using namespace std;

class Queue{
	struct node{
		int data;
		node *link;
	}*p,*r;
	
	public:
		void enQueue(int);
		void deQueue();
		void display();
		
	Queue(){
		p = NULL;
		r = NULL;
	}
};

void Queue::enQueue(int x){
	node *t = new node;
	t->data = x;
	t->link = NULL;
	
	if(p == NULL){
		p = t;
		r = t;
	}
	else{
		r->link = t;
		r = t;
	}
}

void Queue::deQueue(){
	if(p == NULL){
		cout<<"\nQueue is empty..."<<endl;
		return;
	}
	node *t;
	t = p;
	p = p->link;
	delete t;
	
}

void Queue::display(){
	if(p == NULL){
		cout<<"\nQueue is empty..."<<endl;
		return;
	}
	node *q = p;
	while(q != NULL){
		cout<<q->data<<",";
		q = q->link;
	}
	
}

int main(){
	Queue q;
	q.display();
	for(int i=0; i<=20; i++){
		q.enQueue(i);
	}
	q.display();
	for(int i=0; i<=15; i++){
		q.deQueue();
	}
	cout<<endl;
	q.display();
	
	return 0;
}