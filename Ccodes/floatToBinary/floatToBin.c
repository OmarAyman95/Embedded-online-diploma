// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define M2

bool getBitValue(int number,int bit)
{
    return((number & (1U<<bit))==(1U<<bit));
}

void setSign(int number,int *binaryNumber)
{
    if(number<0){binaryNumber[31]= 1;}
    else {binaryNumber[31] = 0;}
}
void setExponet(int number,int *binaryNumber)
{
    int i ;
    for(i=0;i<=31;i++){if(number<pow(2,i))break;}
    int Exponent = i-1+127;
    for(i=23;i<=30;i++)
        {binaryNumber[i] = getBitValue(Exponent,i-23);}
}
void setMantissa( float number,int * binaryNumber)
{
    int i=0;
    int k =0;
    int temp[32]={0};
    int intPart = (int)number;
    float fracPart = number-(float)intPart;
    int reservedForINT=0;


    for(i=0;i<=22;i++)
    {
        temp[i]=getBitValue(intPart,i);
        if(temp[i]==1)
            reservedForINT=i;
    }
    temp[reservedForINT]=0;
     for(i=22-reservedForINT+1;k<reservedForINT;i++){
         temp[i]=temp[k];
         temp[k]=0;
         k++;
     }

    k=22-reservedForINT;
    do
    {
        fracPart*=2.0;
        if(fracPart>=1.0)
            {temp[k]=1;fracPart=fracPart-1.0;}
        else
            temp[k]=0; 
        k--;
    }while(k>=0);


    for(i=0;i<=22;i++)
        binaryNumber[i]=temp[i]; 
}
int *float32ToBinary(float number,int *binaryNumber)
{
 //   static int binaryNumber[32]={0};
    int i;
    setSign((int)number,binaryNumber);
    if(binaryNumber[31]==1){number*=-1;}
    setMantissa(number,binaryNumber);
    setExponet((int)number,binaryNumber);
    return binaryNumber;
}


typedef union 
{
  float numberInFloatIEEE;
  int   numberInHexaFormate;
}floatNumberRepresentation_t;

int main() {
  float  number= -389.28;
  int i;
  static int binaryNumber[32];
  static int binaryNumberX[32];
  #ifdef M1
/*===============================Methode1===========================*/
  floatNumberRepresentation_t U1;
  U1.numberInFloatIEEE = number;
  for(int i=0;i<=31;i++)
  {
    binaryNumberX[i] = getBitValue(U1.numberInHexaFormate,i);
  }
   for(int i=31;i>=0;i--)
  {
     printf("%d",binaryNumberX[i]);
  }

                            printf("\nM1");
#endif
/*===============================Methode2===========================*/

#ifdef M2
  float32ToBinary(number,binaryNumber);
   for(i=31;i>=0;i--)
  {
     printf("%d",binaryNumber[i]);
  }
   printf("\nM2");
#endif
    return 0;
}

    