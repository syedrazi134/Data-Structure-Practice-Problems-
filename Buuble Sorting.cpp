#include<iostream>
using namespace std;

void swap(int a[], int index){
	int temp = a[index];
	a[index] = a[index + 1];
	a[index + 1] = temp;
}

int main(){
	int n;
	cout<<"Enter the size of array: "<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter vlaues in array according to your size: ";
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int j=0; j<n; j++){
		cout<<a[j]<<",";
	}
	cout<<endl;
	
	int i = 0;
	bool swaped;
	do{
		swaped = false;
		for(int j=0; j<n-1-i; j++){
			if(a[j] > a[j+1]){
				swap(a, j);
				swaped = true;
			}
		}
		i++;
	}while(swaped);
	
	for(int k=0; k<n; k++){
		cout<<a[k]<<",";
	}
}