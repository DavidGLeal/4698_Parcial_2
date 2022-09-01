#include <conio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main(){
	int vec1[3];
	int vec2[3];
	int *p1;
	int *p2;
	int res=0;
	p1=&vec1[0];
	p2=vec2;
	
	cout<<"ingrese x, y, z del vector 1"<<endl;
	for(int i=0;i<3;i++){
		cin>>*(p1+i);
	}
	
	cout<<"ingrese x, y, z del vector 2"<<endl;
	for(int i=0;i<3;i++){
		cin>>*(p2+i);
	}
	
	cout<<"el producto escalar es:"<<endl;
	for(int i=0;i<3;i++){
		res=(*(p1+i))*(*(p2+i))+res;
		cout<<	(*(p1+i))*(*(p2+i))<<" ";
	}
	cout<<endl;
	cout<<res;
	return 0;
}
