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
void Rev(char *arr,int size);
void palindrome(char *arr,int size);

/*===================typeDefs======================*/


/*===================private variables=============*/


int main() {
    // Write C code here
   
    char X[] = "level";
    palindrome(X,sizeof(X));
    return 0;
}
void Rev(char *arr,int size)
{
    char tempArr[size];
    for(int i = 0;i<size;i++)
        tempArr[size-2-i] = arr[i];
        tempArr[size-1]='\0';
    strcpy(arr,tempArr);
}
void palindrome(char *arr,int size)
{
    int flag = 0 ;
    char tempArr[size];
    strcpy(tempArr,arr);
    Rev(arr,size);
    flag = strcmp(tempArr,arr);
    //printf("%s\n",arr);
    if(flag == 0)
        printf("YES");
    else 
        printf("NO");
}