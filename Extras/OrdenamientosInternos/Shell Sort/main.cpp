#include<iostream>
#include<conio.h>
#include "Shell.cpp"
using namespace std;

int main()
{
	int n;         
	Shell ordenar;      

	cout<<"Ingrese dimension del arreglo: ";
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)
	{		
		cout<<"Arreglo["<<i+1<<"]=";
		cin>>arr[i];
	}
	ordenar.shellSort(arr,n);

	cout<<"Elementos ordenados por metodo Shell Sort "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<arr[i];
	}

	cout<<endl;
	
	return 0;
}
