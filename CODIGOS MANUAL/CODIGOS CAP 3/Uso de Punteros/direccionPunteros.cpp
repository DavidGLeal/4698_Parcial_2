#include <iostream>
using namespace std;
void paso(int **n2){
	**n2=5;
	cout<<"el valor apuntado por **n2 es:"<<**n2<<endl;
	
}
int main(){
	int num1=0, *p1,**p2;
	p1=&num1;
	p2=&p1;
	paso(p2);
	cout<<"el valor contenido por p2 es:"<<**p2<<endl;
	cout<<"el valor contenido en num1 es:"<<num1<<endl;
	return 0;
}
