#include <iostream>
#include "Proceso.cpp"

using namespace std;
 
int main()
{
    Proceso obj;
    int arr[] = {120, 34, 54, 32, 58, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max, min;
    max = obj.Dato_Max(arr, 0, n);
    min = obj.Dato_Min(arr, 0, n);
    cout << "Maximo: " << max << endl;
    cout << "Minimo: " << min << endl;
    return 0;
}