#include <iostream>
#define ARR_SIZE 200
using namespace std;


class DoubleStack{
    int data[ARR_SIZE];
    int top1;
    int top2;

    public:
        void push(int);
        void pop();
        void display();

    DoubleStack() {
        top1 = -1;
        top2 = ARR_SIZE;
    }

};

void DoubleStack::push(int value) {
    
    if (top1 + 1 == top2) {
        cout << "\nStack overflow! Unable to push " << value << ".\n";
        return;
    }

    if (value%2 == 0) {
        // Push to the small-value stack
        data[++top1] = value;
    } else {
        // Push to the large-value stack
        data[--top2] = value;
    }

    return;
}

void DoubleStack::pop(){
    if(top1 < 0 || top2 >= ARR_SIZE){
        if(top1 < 0){
            cout<<"\nStack1 is empty..."<<endl;
        }
        else if(top2 >= ARR_SIZE){
             cout<<"\nStack2 is empty..."<<endl;
        }
        else if(top1 < 0 && top2 >= ARR_SIZE){
            cout<<"\nBoth Stacks are empty..."<<endl;
            return;
        }
    }

    if(top1 >= 0){
        cout<<"From Stack1: "<<data[top1--]<<" is deleted...\n";
    }
    if(top2 < ARR_SIZE){
        cout<<"From Stack2: "<<data[top2++]<<" is deleted...\n";
    }


}


void DoubleStack::display(){

    if(top1 < 0 || top2 >= ARR_SIZE){
        if(top1 < 0){
            cout<<"\nStack1 is empty..."<<endl;
        }
        else if(top2 >= ARR_SIZE){
             cout<<"\nStack2 is empty..."<<endl;
        }
        else if(top1 < 0 && top2 >= ARR_SIZE){
            cout<<"\nBoth Stacks are empty..."<<endl;
            return;
        }
    }

	if(top1 >= 0){
		cout<<"\nStack 1:\n";
   		 for(int i=top1; i>=0; i--){
        	cout<<data[i]<<",";
    	}
	}
    
    if(top2 < ARR_SIZE){
    	cout<<"\nStack 2:\n";
	    for(int i=top2; i<ARR_SIZE; i++){
	        cout<<data[i]<<",";
	    }
	}

}


int main(){
    DoubleStack s;
    s.display();
    for(int i=0; i<=100; i++){
        s.push(i);
    }
    s.display();
    for(int i=0; i<=50; i++){
        s.pop();
    }
    s.display();



    return 0;
}
