#include <stdio.h>

int Ack(long int m,long int n)
{
    if(m==0){
        return n+1;
    }
    else if(m>0 && n==0){
        return Ack(m-1,1);
    }
    else if(m>0 && n>0){
       return Ack(m-1,Ack(m,n-1));
    }
    
}



int main(){
    long int inputM,inputN,ans=0;
    printf("m = ");
    scanf("%ld)",&inputM);
    printf("n = ");
    scanf("%ld)",&inputN);
    ans=Ack(inputM,inputN);
    printf("Ackermann ans = %ld",ans);
    
}