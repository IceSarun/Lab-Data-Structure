#include <stdio.h>

int a(long int n,long int sum)
{
    if(n==1){
        return sum+2;
    }
    else{
       return a(n-1,sum+3);
    }
    
}

int main(){
    long int input,anwser=0;
    scanf("%ld",&input);
    anwser=a(input,anwser);
    printf("%ld",anwser);
    
}