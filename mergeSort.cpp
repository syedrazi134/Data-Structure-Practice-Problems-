#include<iostream>
using namespace std;

void mergesort(int list[], int first, int last){ 
	if( first < last ){ 
	    int mid = (first + last)/2; 
	    // Sort the 1st half of the list 
	    mergesort(list, first, mid); 
	    // Sort the 2nd half of the list 
	    mergesort(list, mid+1, last); 
	}
} 
 
void merge(int list[], int first, int mid, int last) { 
	// Initialize the first and last indices of our subarrays 
	int firstA = first; 
	int lastA = mid; 
	int firstB = mid+1; 
	int lastB = last; 
	 
	int index = firstA;   // Index into our temp array 
	int tempArray[first + last];
	 
	while (firstA <= lastA){ 
		tempArray[index] = {list[first]}; 
		firstA = firstA + 1;
		index = index + 1;
	} 
	while ( firstB <= lastB ){ 
		tempArray[index] = {list[firstB]}; 
		firstB = firstB + 1; 
		index = index + 1 ;
	} 
	// Finally, we copy our temp array back into our original array 
	index = first; 
	while (index <= last){ 
		list[index] = {tempArray[index]}; 
		index = index + 1;
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
	
	mergesort(a, 0, n-1);
	
	cout<<endl<<"Array after sorting: ";
	for(int j=0; j<n; j++){
		cout<<a[j]<<",";
	}
	cout<<endl;
	
	return 0;
}