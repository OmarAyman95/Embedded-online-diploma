#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

/*==================Includes=======================*/


/*=====================MACRos======================*/

//#define main __main
/*===================prototypes====================*/
int fib1(int n);
int fib2(int n);
int fib3(int n);
/*===================typeDefs======================*/


/*===================private variables=============*/

int main() {
   
   int n = 9 ; 
  printf("fib1(%d) : {%d}\n",n,fib1(n));
  printf("fib2(%d) : {%d}\n",n,fib2(n));
  printf("fib3(%d) : {%d}\n",n,fib3(n));
    return 0;
}
//Dynamic method
int fib1(int n)
{
    int Fn_1=0;
    int Fn = 1;
    int Ftemp=0;
    int i = 2;

    for(;i<=n;i++)
    {
        Ftemp = Fn;
        Fn = Fn_1 + Fn;
        Fn_1 = Ftemp;
    }
    return Fn;
}

//recursion method
int fib2(int n)
{
    if (n <= 1)
        return n;
    return fib2(n - 1) + fib2(n - 2);
}

//Binet’s formula Method
int fib3(int n)
{
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}