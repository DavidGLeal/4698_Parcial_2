#include <iostream>
/*programa que compara las salidas de
un puntero y un puntero doble que apuntan
a un arreglo*/
using namespace std;
int main()
{
    int arr[5]={1,2,3,4,5};
    int *p=&arr[0];
    int **p2=&p;
    int n;
    for(int i=0;i<5;i++){
        cout<<*(p+i)<<"  "<<(p+i)<<" "<<**(p2)<<" "<<*p2<< " "<<p2<<endl;
    }
    cout<<endl<<endl;
    for(int i=0;i<5;i++){
        p=&arr[i];
        cout<<**p2<<" "<<*p2<<endl;
    }
    return 0;
}
