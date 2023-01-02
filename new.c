#include <stdio.h>
#include <math.h>
typedef struct{
    int id;
    char name[100];
    int  score;
}Patient;

void bsortDesc(Patient list[],int s)
{
    int i, j;
    Patient temp;

    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (list[j].id >list[j + 1].id)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            } 
        }
    }
}


int main(){
    int num_pateint;
    int i=0;
    scanf("%d",&num_pateint);
    if(num_pateint==0){
        printf("Nothing to show");
    }
    else if(num_pateint<0){
        printf("ErRor.!");
    }
    else{
        Patient person[num_pateint];
        Patient mostscore[num_pateint];
        float ans=0;
        for(;i<num_pateint;i++){
            scanf("%d",&person[i].id);
            scanf("%s",person[i].name);
            scanf("%d",&person[i].score);
            ans=ans+person[i].score;
        }
        ans=ans/num_pateint;
        // printf("Average: %.1f",ans);

        bsortDesc(person,num_pateint);

        printf("All patient:\n");
        for(i=0;i<num_pateint;i++){
             printf("  %02d %-10s %d\n",person[i].id,person[i].name,person[i].score);
        }
        printf("Critical:\n");
        for(i=10;i>0;i--){
            int c=0;
            for(int j=0;j<num_pateint;j++){
                if(person[j].score==i){
                    printf("  %02d %-10s %d\n",person[j].id,person[j].name,person[j].score);
                    c=c+1;
                }
            }
            if(c>0){
                break;
            }
        }
        
        ans=ceil(ans*10);
        ans=ans/10;
        printf("Average: %.1f",ans);


    }
}