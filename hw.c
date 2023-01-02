#include <stdio.h>

typedef struct{
    char name[100];
    int  score;
}Student;


int main(){
   int i=0;
   double ans=0,scoreans;
   Student person[5];

   for ( i=0;i<5;i++){
        printf("Name : ");
        scanf("%s",person[i].name);
        printf("Score : ");
        scanf("%d",&person[i].score);
        ans=ans+person[i].score;
    }

    scoreans=ans/5;
    printf("Average Score= %.2lf\n",scoreans);
    for ( i=0;i<5;i++){
        if(person[i].score>scoreans){
            printf("Name = %s , Score = %d\n",person[i].name,person[i].score);
        }
    }

}

