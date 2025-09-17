#include<iostream>
using namespace std;

/*void MaxTemp(float A[]){
	float maxTemp = A[0];
	
	for( int i=0 ; i<=6 ; i++){
		if(A[i+1]>maxTemp)
			maxTemp = A[i+1];
			
		else
			continue;
	}
	
	cout<<"So, The greater temp of the week is:"<<maxTemp;
}





/*int AverageMarks(int marks[]){
	int Sum = 0;
	for(int i=0; i<=9; i++){
		Sum += marks[i];
	}
	
	float averageMarks = Sum / 10;
	
	return averageMarks;
	
	
}
*/

int main(){
	
//Activity no 4...
	int Array[10];
	
	
//Acitivity no 4...
/*	float Temp[7];
	
	for( int i=0; i<=9; i++){
		cin>> Temp[i];
	}
	
	MaxTemp(Temp);
	
	
	
	
	
	
	
	
// Activity no 3...
/*	int Marks[10];
	
	cout<<"Enter the Marks of Students consective:";
	
	for(int i=0; i<=9; i++){
		cin>>Marks[i];
	}
	
	float aveMarks = AverageMarks(Marks);
	
	cout<< "Average Marks of the whole class are:"<<aveMarks;
	
	
	
	
	
//Activity no 2...
/*	int pIncome;
	float cGPA;
	
	cout<<"Enter the Income of Parant:";
	cin>>pIncome;
	cout<<"Enter the cGPA of Student:";
	cin>> cGPA;
	
	if(pIncome < 100000){
		if(cGPA == 4){
			cout<< "Congradulations!! You have got full Scholarship...";
		}
		else if(cGPA > 3.0 && cGPA < 4.0){
			cout<< "Congradulations!! You have got half scholarship...";
		}
		else if(cGPA > 2.5 && cGPA < 3.0){
			cout<< "Congradulations!! You have got Quarter Scholarship...";
		}
		else{
			cout<< "Sorry! You are not eligible for this scholarship...";
		}
	}
	
	else if(pIncome > 100000 && pIncome < 150000){
		
		if(cGPA == 4.0){
			cout<< "Congradulations!! You have got half scholarship...";
		}
		else if(cGPA > 3.0 && cGPA < 4.0){
			cout<< "Congradulations!! You have got Quarter Scholarship...";
		}
		else{
			cout<< "Sorry! You are not eligible for this scholarship...";
		}
	}
	
	else if(pIncome > 150000 && pIncome < 200000){
		
		if(cGPA == 4.0){
			cout<< "Congradulations!! You have got Quarter Scholarship...";
		}
		else{
			cout<< "Sorry! You are not eligible for this scholarship...";
		}
		
	}
	
	else{
		cout<< endl;
		cout<< "Sorry! You are not eligible for this scholarship...";
	}
		
	
	
	
//Activity no 1...
	/*int a,b,c;
	float result;
	cin>>a>>b>>c;
	
	result = (float)((b*b)-(4*a*c)) / (2*a);
	
	cout<< "Result is "<<result;*/
	
	return 0;
}