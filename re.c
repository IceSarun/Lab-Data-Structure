#include <stdio.h>

int a(long int n)
{
    long int ans=0;
    if(n==1){
        ans=2;
    }
    else{
        ans=a(n-1)+3;
    }
    return ans;
}

int main(){
    long int input,anwser;
    scanf("%ld",&input);
    anwser=a(input);
    printf("%ld",anwser);
    
}