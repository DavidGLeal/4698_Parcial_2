#include<iostream>
#include "Bucket.cpp"
using namespace std;
int main()
{
	Bucket buckets;
	
    int n,*arr,i;
    int *bucket[10];
    cout << "Ingresa el numero de elementos: ";
    cin>>n;
    arr=new int[n+1];
    for(i=0;i<10;i++)
        bucket[i]=new int[n];
    cout << "Ingrese elementos:" << endl;
    for(i=0;i<n;i++)
        cin>>arr[i];
    buckets.bucketSort(arr,bucket,n);
   
    cout << "Arreglo ordenado: ";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}