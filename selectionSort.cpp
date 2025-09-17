#include<iostream>
using namespace std;

int findMin_Index(int[], int, int);
void swap_Elems(int, int, int);
void select_andSort(int[], int);

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
	
	select_andSort(a, n);
	
	cout<<endl<<"Array after sorting: ";
	for(int j=0; j<n; j++){
		cout<<a[j]<<",";
	}
	cout<<endl;
	
	return 0;
}

int findMin_Index(int a[], int size, int startIndex){  
	int i=startIndex;     
	int min = i;
	 
	for(i; i<size; i++){ 
		if(a[i] < a[min]){ 
		   min = i; 
		} 
	}	
	  
	return min; 
} 
 
void swap_Elems(int a[], int i, int j){ 
	int temp = a[i]; 
	a[i] = a[j]; 
	a[j] = temp; 
} 
 
void select_andSort(int a[], int size){ 
	int minIndex; 
	for(int i=0; i<size; i++){ 
		minIndex = findMin_Index(a, size ,i); 
		swap_Elems(a, i, minIndex);  
	}
	 
} 