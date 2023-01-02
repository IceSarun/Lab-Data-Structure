#include <stdio.h>


void fib(unsigned long long int n)
{
  unsigned long long int a = 1, b = 1, c, i;
  if( n == 0){b=0;}
  for (i = 2; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
  printf("%llu\n",b);
}

int main(){
    unsigned long long int input;
    scanf("%llu",&input);
    if(input>0){
        for(unsigned long long int i=0;i<input;i++){
            fib(i);
        }
    }

    
}