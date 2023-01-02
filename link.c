#include <stdio.h>
#include <stdlib.h>

typedef struct nd{
    int  num;
    struct nd *next;
}Node;

void main(){
    Node* first =NULL;
    Node* second =NULL;
    Node* last =NULL;

    first =(Node*) malloc(sizeof(Node));
    second =(Node*) malloc(sizeof(Node));
    last =(Node*) malloc(sizeof(Node));

    first->num=1;
    first->next=second;

    second->num=5;
    second->next=last;

    last->num=3;
    last->next=NULL;


}