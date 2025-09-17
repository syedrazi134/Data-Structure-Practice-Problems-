#include<iostream>
using namespace std;

class PatientManagementSystem{
	struct node{
		string pName;
		int priority;
		node* next;
	}*head;
	
	public:
	PatientManagementSystem(){
		head = NULL;
	}
	
	
	void insertNewPatient(string name, int priority){
		node* q = new node;
		q->pName = name;
		q->priority = priority;
		q->next = NULL;
		
		if(head == NULL){
			head = q;
			return;
		}
		
		if(q->priority < head->priority){
			q->next = head;
			head = q;
			return;
		}
		
		node* r = head;
		while(r->next != NULL && q->priority < r->next->priority){
			r = r->next;
		}
		
		q->next = r->next;
		r->next = q;
		return;
		
	}
	
	void displayPatients(){
		if(head == NULL){
			cout<<"List is empty..."<<endl;
			return;
		}
		node* q = head;
		while(q != NULL){
			cout<<endl<<"Patient Name: "<< q->pName << " Priority:"<< q->priority;
			q = q->next;
		}
	}
};

int main(){
	PatientManagementSystem p;
	p.insertNewPatient("ali", 1);
	p.insertNewPatient("ahmad", 2);
	p.insertNewPatient("asif", 1);
	p.insertNewPatient("raza", 4);
	p.insertNewPatient("mohsin", 3);
	
	p.displayPatients();
	
	
	return 0;
}