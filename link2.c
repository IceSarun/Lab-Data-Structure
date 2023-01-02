#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int  num;
    struct nd *next;
}Node;

typedef struct linked_list{
    int Length;
    Node *head;
    Node *tail;
}NumList;

Node *newNode(){
    Node *p;
    p=(Node*) malloc (sizeof(Node));
    p->next=NULL;
    return p;
}

void initList (NumList *n){
    n->head=NULL;
}

// void appendHeadList(NumList *s,Node *p){
//     if(s->head==NULL){
//         s->head=p;
//     }
//     else{
//         p->next=s->head;
//         s->head=p;
//     }
// }

void insertEnd(NumList *s,Node *p){
    if(s->head==NULL){
        s->head=p;
    }
    else {
        s->tail->next=p;
        }
    s->tail=p;
    }


void printNumList(NumList L){
    Node *pCurr =L.head;
    while(pCurr != NULL){
        printf("Num : %d\n",pCurr->num);
        pCurr=pCurr->next;    
    }
}

int main(){
    NumList NL;
    initList(&NL);
    for(int i=0;i<3;i++){
        Node *N = newNode();
        N->num=i;
       insertEnd(&NL,N);
    }
    printNumList(NL);
    return 0;
}