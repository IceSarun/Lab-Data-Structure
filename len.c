#include <stdio.h>
int main(){
    char string[100];
    int i=0,count=0;
    printf("Input : ");
    gets(string);
    for(i=0; *(string+i)!='\0';i=i+1){
        // printf("%d , %c\n",i,*(string+i));
        count=count+1;
        
    }
    printf("Length : %d",count);

}