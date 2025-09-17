#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;

class Stack{
	int stk[5];
	int top;
	
	public:
		void push(int);
		void pop();
		void display();
		
	Stack(){
		top = -1;
	}
};

void Stack::push(int x){
	
	if(top >= 4){
		cout<<"\nStack overflow..."<<endl;
		return;
	}
	
	stk[++top] = x;
	cout<<"\nInserted: "<< x <<endl;
	
}

void Stack::pop(){
	if(top < 0){
		cout<<"\nStack underflow..."<<endl;
		return;
	}
	
	cout<<endl<<stk[top--]<<" Deletet"<<endl;
	
}

void Stack::display(){
	if(top < 0){
		cout<<"\nStack empty..."<<endl;
		return;
	}
	cout<<endl;
	for(int i=top; i>=0; i--){
		cout<<stk[i]<<",";
	}
	
}

int main(){
	Stack st;
	int ch;
	
	while(1){
		cout<<"Operations on Stacks: "<<endl;
		cout<<"1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ";
		cin>>ch;
		
		switch(ch){
			case 1:
				int v;
				cout<<"\nEnter value: ";
				cin>>v;
				st.push(v);
				break;
			case 2:
				st.pop();
				break;
			case 3:
				st.display();
				break;
			case 4:
				exit(1);
			
			default:
				cout<<"\nInvaled Input..."<<endl;
				break;
		}
		
		cout<<endl;
		system("pause");
		
	}

	return 0;
}