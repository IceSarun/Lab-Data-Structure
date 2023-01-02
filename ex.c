#include <stdio.h>
int main(){
    struct address{
        char district[20];
        char county[20];
    };
    struct Thaiflower{
        char code[20];
        char name[20];
        float price;
        struct address flower_addr;
    }flower[3];

    for(int i=0;i<3;i++){
        printf("Enter code : ");
        scanf("%s",flower[i].code);
        printf("Enter name : ");
        scanf("%s",flower[i].name);
        printf("Enter price : ");
        scanf("%f",&flower[i].price);
        printf("Enter district : ");
        scanf("%s",flower[i].flower_addr.district);
        printf("Enter county : ");
        scanf("%s",flower[i].flower_addr.county);
    }
    
    for(int i=0;i<3;i++){
        printf("-----Thai Flower-----\n");
        printf("Code = %s\n",flower[i].code);
        printf("Name = %s\n",flower[i].name);
        printf("Price = %.2f\n",flower[i].price);
        printf("-----address-----\n");
        printf("District = %s\n",flower[i].flower_addr.district);
        printf("County = %s\n",flower[i].flower_addr.county);
        printf("-----------------\n");
    }
}   