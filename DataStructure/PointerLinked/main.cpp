#include<iostream>
#include<cstdlib>

#define endl '\n'

using namespace std;

void show_array(int *ar,int size){
	cout << "arr is :" ;
	for (int i=0; i<size; i++){
		cout << ar[i] << " ";
	}
}
		
int main(){
	int a =5l;
	int *pa = &a;
	cout << "a is " << a << endl;
	cout << "pa is " << *pa << endl;
	cout << "a address is " << &a << endl; 
	cout << "pa address is " << pa << endl; 

	cout << "change pa value is 30" << endl;
	*pa = 30;
	cout << "a is " << a << endl;
	cout << "pa is " << *pa << endl;
	cout << "a address is " << &a << endl; 
	cout << "pa address is " << pa << endl; 

	int arr[5] = {21,442,33,314,221};
	int *parr = arr;
	show_array(arr,5);
	show_array(parr,5);

	cout << "change arr element" << endl;
	arr[2] =45;
	show_array(arr,5);
	show_array(parr,5);

	cout << "change arr element" << endl;
	parr[2] =45;
	show_array(arr,5);
	show_array(parr,5);

	cout<< endl  << *arr << endl;
	cout << (arr)+1 << endl;
	cout << *(arr+1) << endl;

	int* darr = (int*)malloc(sizeof(int)*8);

	darr[0] = 32;
	show_array(darr,8);

	free(darr);

	cout << darr << endl;

}

