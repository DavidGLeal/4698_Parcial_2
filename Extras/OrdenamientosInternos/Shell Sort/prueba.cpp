#include<iostream>
using namespace std;


//main program
int main()
{
	int size;               

	cout<<"Ingrese dimension del arreglo: ";
	cin>>size;

	int sort[size];
	for(int i=0;i<size;i++)
	{		
		cout<<"Arreglo["<<i+1<<"]=";
		cin>>sort[i];
	}

	shellSort(sort,size);

	cout<<"Elementos ordenados por metodo Shell Sort "<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"\t"<<sort[i];
	}

	cout<<endl;
	
	return 0;
}