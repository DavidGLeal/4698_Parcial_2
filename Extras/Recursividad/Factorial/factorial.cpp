#include "factorial.h"
#include <iostream>
#include <conio.h>

using namespace std;
 
factorial::factorial(int c){
	this->numero= c; 	
}

int factoriales(int c){
    if(c==0){ //Caso Base
        return 1;
    }
    else{ //Caso general
        return c*factoriales(c-1);
    }
}


/* 4!=4*3!    --> 4*6 =24
    3!=3*2!   --> 3*2 =6
     2!=2*1!  --> 2*1 =2
      1!=1*0! --> 1*1 =1
       0!=1
*/
