#include<iostream>
#include<cstdlib>

using namespace std;

class List{	
public:
	struct node{
		int data;
		node *link;
	}*p;
	
public:
	void insertLast(int);
	void insertBeg(int);
	void printReverse(node*);
	void printReverseWithOutRecurssion();
	void reverseOrder();
	void evenoddGroup();
	void swapTheNodes(int, int);
	void splitListIntoTwoOfEvenAndOdd();
	void removeDuplicates();
	void delBeg();
	void delLast();
	void deleteNode(int);
	void seekNode(int);
	void displayList();
		
	List(){
		p = NULL;
	}
	
};

void List::insertLast(int x){
	node *q, *t;
	
	if(p == NULL){
		q = new node;
		q->data = x;
		q->link = NULL;
		p = q;
		return;
	}
	
	else{
		q = p;
		while (q->link != NULL){
			q = q->link;
		}
		t = new node;
		t->data = x;
		t->link = NULL;
		q->link = t;
		return;
	}
}

void List::insertBeg(int x){
	node *q;
	
	if ( p == NULL){
		q = new node;
		q->data = x;
		q->link = NULL;
		p = q;
		return;
	}
	else{
		q = new node;
		q->data = x;
		q->link = p;
		p = q;
		return;
	}
}

void List::evenoddGroup(){
	node *q, *r;
	if(p==NULL){
		cout<<"List is Empty...";
		return;
	}
	else{
		q = p;
		while (q != NULL){
			r = q;
			if(q->data % 2 == 0){
				while(r != NULL){
					if (r->data % 2 != 0)
					break;
					r = r->link;
				}
				if(r != NULL){
					int temp = r->data;
					r->data = q->data;
					q->data = temp;
				}
			}
			q = q->link;
		}
	}
}

void List::swapTheNodes(int x, int y){
	if(p == NULL){
		cout<<"List is empty..."<<endl;
		return;
	}
	
	if (x == y) return;

    node *prevX = NULL, *currX = p;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->link;
    }

    node *prevY = NULL, *currY = p;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->link;
    }

    if (!currX || !currY) return;

    if (prevX) prevX->link = currY;
    else p = currY;

    if (prevY) prevY->link = currX;
    else p = currX;

    node* temp = currY->link;
    currY->link = currX->link;
    currX->link = temp;
	
}



void List::delBeg(){
	node *q;
	if(p==NULL){
		cout<<"List is Empty..."<<endl;
		return;
	}
	else{
		q = p;
		p = p->link;
		q->link = NULL;
		delete q;
		return;
	}
}

void List::delLast(){
	node *q, *r;
	if(p==NULL){
		cout<<"List is Empty..."<<endl;
		return;
	}
	else{
		q = p;
		while(q->link->link != NULL){
			q = q->link;
		}
		r = q->link;
		q->link = NULL;
		delete r;
		return;
	}
}

void List::deleteNode(int pos){
	node *q, *t;
	if(p==NULL){
		cout<<"List is Empty..."<<endl;
		return;
	}
	else{
		q = p;
		for(int i=1; i<pos-1; i++){
			q = q->link;
		}
		cout<< "The deleting term will be "<<q->link->data<<endl;
		t = q->link;
		q->link = q->link->link;
		delete t;
		return;
	}
} 

void List::printReverse(node* q){
	if(q==NULL){
		return;
	}
	else{
		printReverse(q->link);
		cout<<q->data<<",";
	}
}

void List::printReverseWithOutRecurssion(){
	if (p==NULL){
		cout<<"List is empty...";
		return;
	}
	node *q;
	q = p;
	int count = 0;
	while(q != NULL){
		q = q->link;
		++count;
	}
	
	for(int i=count-1; i>=0; i--){
		q = p;
		for(int j=0; j<i; j++){
			q = q->link;
		}
		cout<<q->data<<",";
	}
	
}

void List::reverseOrder(){
	if(p == NULL){
		cout<<"\nList is Empty...\n";
		return;
	}
	node *next, *prev = NULL;
	while (p != NULL) {
        next = p->link;  
        p->link = prev;  
        prev = p;        
        p = next;
    }
    p = prev;
}


void List::displayList(){
	node *q;
	
	if(p==NULL){
		cout<<"List is Empty..."<<endl;
		return;
	}
	
	q = p;
	while(q != NULL){
		cout<< q->data <<",";
		q = q->link;
	}
	
}

void List::removeDuplicates(){
	if(p==NULL){
		cout<<"\nList is empty...\n";
		return;
	}
	node *q, *r, *t;
	q = p;
	int count = 0;
	
	while(q != NULL){
		r = q->link;
		count = 0;
		while(r!=NULL){
			if(r->data == q->data){
				count++;
			}
			r = r->link;
		}
		
		if(count > 0){
			if(q == p){
				t = q;
				q = q->link;
				p = q;
				delete t;
				continue;
			}
			else{
				r = p;
				while(r->link != q){
					r = r->link;
				}
				r->link = q->link;
				t = q;
				q = q->link;
				delete t;
				continue;
			}
		}
		
		q = q->link;
	}
	
}


int main(){
	List l;
	int ch, v, p, ps;

	do
	{
	cout << "\nOperations on List..";
	cout << "\n1. Insertion\n2. Deletion\n3. Display\n4. Seek\n5. Reverse order of list\n6. Print Reverse\n7. Even/Odd Groups\n8. To Swap Nodes\n9. Print Reverse Without using Recurssion\n10. Remove Duplicates\n11. Exit";
	cout << "\nEnter your choice: ";
	cin >> ch;
	
	switch (ch)
	{
		case 1:
			cout << "\n1. Insertion at the beginning\n2. Insertion at the end";
			cout << "\n3. Enter your choice:";
			cin >> ps;
			//cout << "\nEnter the value to insert: ";
			//cin >> v;
		
			switch (ps)
			{
				case 1:
					l.insertBeg(v);
					break;
				case 2:
					for(int i=10; i<=20; i++){
						l.insertLast(i);
					}
					for(int i=10; i<=20; i++){
						l.insertLast(i);
					}
					break;
				
				default:
					cout << "\nThe choice is invalid..";
					return 0;
			}
			break;
			
		case 2:
			cout << "\n1. Delete the first element\n2. Delete the last element";
			cout << "\n 3. Enter the element to delete from list";
				
			cout << "\nEnter your choice: ";
			cin >> ps;
			
			switch (ps)
			{
				case 1: 
					l.delBeg();
					cout << "\nThe list after deletion: ";
					l.displayList();
					break;
					
				case 2: 
					l.delLast();
					cout << "\nThe list after deletion: ";
					l.displayList();
					break;
				
				case 3:
					l.displayList();
					cout << "\nEnter the position of node to delete: ";
					cin >> v;
					l.deleteNode(v);
					cout << "\nThe list after deletion: ";
					l.displayList();
					break;
					
				default:
					cout << "\nThe option is invalid..";
					break;
			
			}
			break;
			
		case 3:
			l.displayList();
			break;
			
		case 4:
			l.displayList();
			cout << "\nEnter the element to search: ";
			cin >> v;
		//	cout << "\nThe position of the element " << v << " is " << l.seekNode(v);	
		//write system pause here	
			break;
			
		case 5:
			l.reverseOrder();
			break;
			
		case 6:
			l.printReverse(l.p);
			break;
			
		case 7:
			l.evenoddGroup();
			cout<<"\nList after grouping: ";
			l.displayList();
			break;
			
		case 8:
			int v1, v2;
			cout<<"\nEnter the two values to whom you want to swap the related nodes: ";
			cin>>v1;
			cin>>v2;
			l.swapTheNodes(v1, v2);
			l.displayList();
			break;
		
		case 9:
			cout<<endl;
			l.printReverseWithOutRecurssion();
			break;
		
		case 10:
			l.removeDuplicates();
			cout<<"\nDuplicates has removed if exist...\n";
			break;		
		case 11:
			exit(1);
			
		default:
			cout << "\nThe option is invalid..\n";
			break;
	}
	
	//write system pause here
	cout<<endl;
	system("pause");
	
	} while (ch != 11);
	
	//write system pause here
	system("pause");
	
	
	return 0;

}