#include <bits/stdc++.h>
using namespace std;
 

void imprimirVector(vector<int> v)
{

    for_each(v.begin(), v.end(), [](int i)
    {
        std::cout << i << " ";
    });
    cout << endl;
}
 
int main()
{
    vector<int> v {4, 1, 3, 5, 2, 3, 1, 7};
 
    imprimirVector(v);
    vector<int>:: iterator p = find_if(v.begin(), v.end(), [](int i)
    {
        return i > 4;
    });
    cout << "El primer numero mayor que 4 es : " << *p << endl;
 
    sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
    {
        return a > b;
    });
 
    imprimirVector(v);

    int count_5 = count_if(v.begin(), v.end(), [](int a)
    {
        return (a >= 5);
    });
    cout << "El número de elementos mayor o igual a 5 es:  "
         << count_5 << endl;
 
    p = unique(v.begin(), v.end(), [](int a, int b)
    {
        return a == b;
    });

    v.resize(distance(v.begin(), p));
    imprimirVector(v);
 
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int f = accumulate(arr, arr + 10, 1, [](int i, int j)
    {
        return i * j;
    });
 
    cout << "El factorial de 10 es: "<< f << endl;
 

    auto square = [](int i)
    {
        return i * i;
    };
 
    cout << "El cuadrado de 5 " << square(5) << endl;
}