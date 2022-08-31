#pragma once
#include <iostream>
#include <time.h>
#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <windows.h>


using namespace std;

class BigO{
    public:
    float funcionPascal(int n);
    float imprimirPascal(int n);
    float preBMBc(char *P, int m, int tabla[]);
    float BMH( char *T, int n , char *P, int m);
    float imprimirBMH(char *T, int n , char *P, int m);
    signed int  rep  ;            
    signed int  comp ;     

};


float BigO :: funcionPascal(int n){

    for (int i = 1; i <= n; i++)
	{ 
		int proceso = 1; 

		for (int j = 1; j < (n - i + 1); j++){
			cout << " ";
		}

		for (int k = 1; k <= i; k++)
		{

			cout << "  " << proceso ;
			proceso = proceso * (i - k) / k;
		}

		cout << endl << endl;
	}
    cout << endl;
    clock_t t;
    t = clock();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
    return time_taken;
}

float BigO :: imprimirPascal(int n){
    for (int i = 1; i <= n; i++)
    { 
        int proceso = 1; 

        for (int j = 1; j < (n - i + 1); j++){
            cout << " ";
        }

        cout << endl << endl;
    }
    cout << endl;
    clock_t t;
    t = clock();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
    return time_taken;
}


float BigO :: preBMBc(char *P, int m, int tabla[])
{
    int i;
    for (i = 0; i < 256; ++i)
        tabla[i] = m;                  

    for (i = 0; i < m - 1; ++i)
    {
        tabla[P[i]] = m - i - 1;  

    } 
    clock_t t;
    t = clock();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    return time_taken; 

}


float BigO ::BMH( char *T, int n , char *P, int m)
{
    int  j , bmBC[256] ;
    char c ;

    preBMBc(P, m, bmBC) ; 


    j = 0;
    while (j <= n - m)
    {
        c = T[j + m - 1] ;

        if ( P[m - 1] == c && memcmp(P, T + j, m - 1) == 0 )
        {
             cout<<" * Encontrado en : "<< j + 1 << endl; 
             rep ++ ;
        }

        j = j + bmBC[c] ;     comp ++ ;                                   

    }
    clock_t t;
    t = clock();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    return time_taken;
} 

float BigO :: imprimirBMH(char *T, int n , char *P, int m)
{
    int  j , bmBC[256] ;
    char c ;

    preBMBc(P, m, bmBC) ;
    j = 0;
    while (j <= n - m)
    {
        c = T[j + m - 1] ;
        if ( P[m - 1] == c && memcmp(P, T + j, m - 1) == 0 )
        {
             cout<<" * Encontrado en : "<< j + 1 << endl; 
             rep ++ ;
        }
        j = j + bmBC[c] ;     comp ++ ;                                   
    }
    clock_t t;
    t = clock();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    return time_taken;
}