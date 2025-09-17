#include<iostream>
#include<cstdlib>
using namespace std;

class Doubly{
	struct node{
		int info;
		node* next;
		node* prev;
	}*p;
	
	public:
		void creatNode(int);
		void creatBefore(int, int);
		void creatAfter(int, int);
		void deleteNode(int);
		void addData();
		void reverseListOrder();
		void evenOddOrder();
		void swapNodes(int, int);
		void displayList();
		void displayReverse();
		
	Doubly(){
		p = NULL;
	}
		
};

void Doubly::creatNode(int x){
	node *q, *t;
	t = new node;
	t->info = x;
	t->next = NULL;
	if(p == NULL){
		t->prev = NULL;
		p = t;
		return;
	}
	
	else{
		q = p;
		while (q->next != NULL){
			q = q->next;
		}
		q->next = t;
		t->prev = q;
		
	}
}


void Doubly::deleteNode(int x){
	node *q;
	q = p;
	if(q->info == x){
		q->next->prev = NULL;
		p = q->next;
		delete q;
		return;
	}
	
	while(q->next != NULL){
		q = q->next;
		if(q->info == x)
		break;
	}
	
	if(q->next == NULL && q->info == x){
		q->prev->next = NULL;
		delete q;
		return;
	}
	else if(q->info == x){
		q->next->prev = q->prev;
		q->prev->next = q->next;
		delete q;
		return;
	}
	
	cout<< "Value not found..."<<endl;
	
}

void Doubly::creatBefore(int x, int pos){
	node *q, *t;
	if (p==NULL){
		cout << "List is Empty..."<<endl;
		return;
	}
	
	q = p;
	for(int i=1; i<pos; i++){
		q = q->next;
		if(q==NULL){
			cout<< "Less number of nodes..."<<endl;
			return;
		}
	}
	t = new node;
	t->info = x;
	
	if(q->prev == NULL){
		t->prev = NULL;
		t->next = q;
		q->prev = t;
		p = t;
		return;
	}
	else{
		t->prev = q->prev;
		q->prev->next = t;
		t->next = q;
		q->prev = t;
		return;
	}
	
	
}

void Doubly::creatAfter(int x, int pos){
	node *q, *t;
	
	if(p==NULL){
		cout<< "List is empty..."<<endl;
		return;
	}
	
	q = p;
	for(int i=0; i<pos; i++){
		q = q->next;
		if(q == NULL){
			cout<< "Less number of nodes..."<<endl;
			return;
		}
	}
	t = new node;
	t->info = x;
	
	if(q->next == NULL){
		q->next = t;
		t->prev = q;
		t->next = NULL;
		return;
	}
	else{
		t->next = q->next;
		q->next->prev = t;
		q->next = t;
		t->prev = q;
		return;
	}
	
}

void Doubly::addData(){
	node *q;
	
	if(p==NULL){
		cout<<"List is empty..."<<endl;
		return;
	}
	
	else{
		int sum = 0, count = 0;
		q = p;
		while (q != NULL){
			sum += q->info;
			count++;
			q = q->next;
		}
		
		cout<<endl<< "Average of the data is: " << (float) sum/count <<endl;
	}
	
}

void Doubly::displayReverse(){
	node *q;
	if(p == NULL){
		cout<<"List is Empty..."<<endl;
		return;
	}
	else{
		q = p;
		while(q->next != NULL){
			q = q->next;
		}
		while(q != NULL){
			cout<< q->info << ",";
			q = q->prev;
		}
		return;
	}
}

void Doubly::displayList(){
	node*q;
	if(p==NULL){
		cout<<"List is Empty..."<<endl;
		return;
	}
	q = p;
	while(q != NULL){
		cout<< q->info << ",";
		q = q->next;
	}
	return;
}

void Doubly::reverseListOrder(){
	if(p == NULL){
		cout<<"\nList is Empty..."<<endl;
		return;
	}
	node *q = NULL, *r = p;
	while(r->next != NULL){
		r = r->next;
	}
	p = r;
	while(r != NULL){
		r->next = r->prev;
		r->prev = q;
		q = r;
		r = r->next;
	}

}

void Doubly::evenOddOrder(){
	if(p == NULL){
		cout<<"\nList is Empty..."<<endl;
		return;
	}
	node *q = p, *r = NULL;

	while(q != NULL){
		r = q->next;
		if(q->info % 2 == 0){
			while(r != NULL){
				if(r->info % 2 != 0){
					break;
				}
				r = r->next;
			}
			if(r != NULL){
				int temp = r->info;
				r->info = q->info;
				q->info = temp;
			}
		}
		q = q->next;
	}
}

void Doubly::swapNodes(int x, int y){
	if(p == NULL){
		cout<<"\nList is Empty..."<<endl;
		return;
	}
	else if(x == y){
		cout<<"\nYou entered invaled values..."<<endl;
		return;
	}
	else{
		node *q = p, *r = p;
		while(q != NULL && q->info != x){
			q = q->next;
		}
		while(r != NULL && r->info != y){
			r = r->next;
		}
		
		if(q == NULL || r == NULL){
			cout<<"\nEntered values not found in the list..."<<endl;
			return;
		}
		
		if(q->prev != NULL){
			q->prev->next = r;
			if(q->next == NULL){
				q->next = r->next;
				r->next = NULL;
			}
			else
				q->next->prev = r;
		}
		else{
			p = r;
			q->next->prev = r;
		}
			
		if(r->prev != NULL){
			r->prev->next = q;
			if(r->next == NULL){
				r->next = q->next;
				q->next = NULL;
			}
			else
				r->next->prev = q;
		}
		else{
			p = q;
			r->next->prev = q;
		}
			
		node *temp = q->prev;
		q->prev = r->prev;
		r->prev = temp;
		
		if(r->next && q->next){
			node *temp1 = q->next;
			q->next = r->next;
			r->next = temp1;
		}
		
		
		
	}
}






int main(){
	Doubly l1;
	int ch, v, p, ps;
	
	do{
		cout<<"Operations on doubly linked list:\n";
		cout<<"1. Creat New Node\n2. Creat Before\n3. Creat After\n4. Delete NOde\n5. Display List";
		cout<<"\n6. Display Reverse\n7. Add Data\n8. Reverse Order\n9. Group Nodes as Enen and Odd\n10. Swap the Specified Nodes\n11. Exit\n";
		cout<<"Enter your choice: ";
		cin>> ch;
		
		switch(ch){
			case 1:
				for(int i=0; i<=50; i++){
					if(i % 2 == 0 && i < 30){
						continue;
					}
					l1.creatNode(i);
				}
				break;
			case 2:
				cout<<"\n Enter the value and position respectively: ";
				cin>> v;
				cin>> ps;
				l1.creatBefore(v, ps);
				cout<<"\nList after changes: ";
				l1.displayList();
				break;
			case 3:
				cout<<"\n Enter the value and position respectively: ";
				cin>> v;
				cin>> ps;
				l1.creatAfter(v, ps);
				cout<<"\nList after changes: ";
				l1.displayList();
				break;
			case 4:
				cout<<"\nEnter the value to which you delete the related node: ";
				cin>> v;
				l1.deleteNode(v);
				cout<<"\nList after changes: ";
				l1.displayList();
				break;
			case 5:
				cout<<"\nList is: ";
				l1.displayList();
				break;
			case 6:
				cout<<"\nList in reverse order: ";
				l1.displayReverse();
				break;
			case 7:
				cout<<"\nAverage of all the data in a list is: ";
				l1.addData();
				break;
			case 8:
				l1.reverseListOrder();
				cout<<"\nList after reversing it's order: ";
				l1.displayList();
				break;
			case 9:
				l1.evenOddOrder();
				cout<<"\nList after changes: ";
				l1.displayList();
				break;
			case 10:
				int v1, v2;
				cout<<"\nEnter two values to which you want to swap the related Nodes respectively: ";
				cin>> v1;
				cin>> v2;
				l1.swapNodes(v1, v2);
				cout<<"\nList after changes: ";
				l1.displayList();
				break;
			case 11:
				exit(1);
				
			default:
				cout<<"Invaled option..."<<endl;
				break;
			
			system("pause");
		}
		
		cout<<"\n"<<endl;
		
	}while(ch != 11);
	
	cout<<"\nSystem Exit..."<<endl;
	system("pause");
	
	
	return 0;
}