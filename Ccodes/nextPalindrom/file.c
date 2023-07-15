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
char * palindrome(char *arr,int size);

/*===================typeDefs======================*/


/*===================private variables=============*/

int main(int argc, char const *argv[])
{
	int i = 0 ;
	int a=100;
	int result = 0 ;
    char buffer[20];

    itoa(a,buffer,10); 
   // printf("%s\n",buffer);
   // printf("%s",palindrome(buffer,strlen(buffer)+1));
	result=strcmp("YES",palindrome(buffer,strlen(buffer)+1));
    while(result !=0 )
    {
    	result=strcmp("YES",palindrome(buffer,strlen(buffer)+1));
    	itoa(++a,buffer,10);
    }
    printf("%d",a-1);
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
char * palindrome(char *arr,int size)
{
    int flag = 0 ;
    char tempArr[size];
    static char retARR[4];
    strcpy(tempArr,arr);
    Rev(arr,size);
    flag = strcmp(tempArr,arr);
    //printf("%s\n",arr);
    if(flag == 0)
    {
        //printf("YES");
        strcpy(retARR,"YES");
    }
    else 
    {
        //printf("NO");
        strcpy(retARR,"NO");
    }
    return retARR;

}
