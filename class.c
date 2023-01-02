#include <stdio.h>

int main(){
    int numTable,numreserve;
    scanf("%d",&numTable);
    int x,y;
    if(numTable<1){
        printf("Error");
    }
    else if(numTable>40){
        printf("Error!");
    }
    else{
        int c=(numTable/6);
        int d=numTable;
        if((numTable % 6)!=0){
            c=c+1;
        }

        int b[c][6]; 
        // printf("x=%d y=6\n",c);
        for(int i=0;i<c;i++){
            for(int j=0;j<6;j++){
                if(d>0){
                    // printf("x=%d y=%d => X\n",i,j);
                    b[i][j]='X';
                    d=d-1;
                }
                else{
                    // printf("x=%d y=%d => ''\n",i,j);
                    b[i][j]='\0';
                }
        }
        }
        scanf("%d",&numreserve);
        for(int i=0;i<numreserve;){
            scanf("%d %d",&x,&y);
            // printf("x=%d y=%d\n",x-1,y-1);
            if(y>6 || (x)>c ){
                printf("%d %d Out of range!\n",x,y);
            }
            else if(y<1 || (x)<1){
                printf("%d %d Out of range!\n",x,y);
            }
            else if(b[x-1][y-1]=='\0'){
                printf("%d %d Out of range!\n",x,y);
            }
            else{
                b[x-1][y-1]='S';
                i++;
            }
        }

        for(int i=0;i<c;i++){
            for(int j=0;j<6;j++){
                if(b[i][j]!='\0'){
                    printf("%c ",b[i][j]);}
            }
            printf("\n");
     }

    }
    

}