#include<iostream>
using namespace std;

class Queue{
	int queue[5];
	int front;
	int rare;
	
	public:
		void enQueue(int);
		void deQueue();
		void display();
		
	Queue(){
		front = 0;
		rare = -1;
	}
};

void enQueue(int x){
	if(rare > 4){
		cout<<"\nQueue overflow..."<<endl;
		return;
	}
	
	queue[++rare] = x;
	
}

void deQueue(){
	if(front > 4){
		cout<<"\nQueue underflow..."<<endl;
		return;
	}
	
	queue[front++];
	
}

void display(){
	
}