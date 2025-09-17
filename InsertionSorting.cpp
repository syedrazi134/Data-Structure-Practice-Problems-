#include<iostream>
using namespace std;

void insertionSort(int arr[], int length){ 
	int i, j, key;
	 
	for (i = 1; i < length; i++){ 
		j = i; 
		while (j > 0 && arr[j - 1] > arr[j]){ 
		   key = arr[j]; 
		   arr[j] = arr[j - 1]; 
		   arr[j - 1] = key; 
		   j--; 
		} 
	}
	
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
	
	cout<<endl<<"Array before sorting: ";
	for(int j=0; j<n; j++){
		cout<<a[j]<<",";
	}
	cout<<endl;
	
	insertionSort(a, n);
	
	cout<<endl<<"Array after sorting: ";
	for(int j=0; j<n; j++){
		cout<<a[j]<<",";
	}
	cout<<endl;
	
	return 0;
}