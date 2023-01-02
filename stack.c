#include<stdio.h>

#include<stdlib.h>
 
#define Size 10
int top=-1;
char stackdata[Size];

int Push(char what)
{
    if (top<Size-1) {
        top++;
        stackdata[top] = what;
        return 1;
    }
    return -1;
}
 
int Pop()
{
    int r;

    if (top>-1) {
        r=stackdata[top];
        stackdata[top]=0;
        top--;
        return r;
    }
    return -1;
}
  
int main()
{
    char string[100];
    gets(string);
    char resualt;
    for(int i=0;string[i]!='\0';i=i+1){
        if(string[i]=='{' || string[i]=='[' || string[i]=='('){
            Push(string[i]);
        }
        else if(string[i]=='}'){
            if(stackdata[top]=='{'){
                resualt=Pop();
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        else if(string[i]==']'){
            if(stackdata[top]=='['){
                resualt=Pop();
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }        
        else if(string[i]==')'){
            if(stackdata[top]=='('){
                resualt=Pop();
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }  
    }
}

 
