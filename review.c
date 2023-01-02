#include <stdio.h> 

typedef struct{
    char name[100];
    double score;
    int id;
}Product;


int main(){
    int amount;
    double ans;
    scanf("%d",&amount);
    if(amount<0){
        printf("ERROR");
    }
    else if(amount==0){
        printf("No reviews found");
    }
    else{
        Product p[amount];
        Product temp;
        for(int i=0;i<amount;i++){
            scanf("%lf %s",&p[i].score,p[i].name);
            p[i].id=i+1;
            // printf("%d\n",p[i].id);
            ans=ans+p[i].score;
        }
        ans=ans/amount;
        printf("Average Score: %.2lf\n",ans);
        for(int i=0; i<amount; ++i) {
            for(int j=i+1; j<amount; ++j) {
                if (p[i].score < p[j].score) {
                    temp= p[i];
                    p[i] = p[j];
                    p[j]= temp;
                }
            }
        }
        for(int i=0;i<amount;i++){
            printf("%.2lf %s (id: %d)\n",p[i].score,p[i].name,p[i].id);
        }

    }
}