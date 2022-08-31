#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main(){
	int arr[10];
	int *a;
	a=&arr[0];
	cout<<"Ingrese 10 numeros: "<<endl;
	for(int i=0;i<10;i++){
		cin >>*(a+i);
	}
	cout<<"los valores ingresados son: "<<endl;
	for(int i=0;i<10;i++){
		cout<<*(a+i)<<" ";
	}
return 0;
}
