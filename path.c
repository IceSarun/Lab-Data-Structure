#include<stdio.h>
#include<stdlib.h>
int count=0;
int** createGraph(const int n) {
    int** adjMatrix = malloc(sizeof(int*)*n);
    for (int i=0; i<n; i++) {
        adjMatrix[i] = malloc(sizeof(int)*n);
        for (int j=0; j<n; j++) 
            adjMatrix[i][j] = 0;
    }
    return adjMatrix;
}

int** createList(const int n) {
    int** ans = malloc(sizeof(int*)*n);
    for (int i=0; i<n; i++) {
        ans[i] = 0;
    }
    return ans;
}

void addEdge(int** adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

int checkPath(int** adjMatrix,int** ans,int u,int v,int n){
    for (int i=0; i<n; i++) {
            if(adjMatrix[u][v]==1){
                ans[count]=v;
                count+1;
            }
            else if(adjMatrix[u][i]==1){
                ans[count]=i+1;
                // printf("ans[%d] = %d\n",count,ans[count]);
                count+=1;
                checkPath2(adjMatrix,ans,i,u,n);
            }
       }

}

int checkPath2(int** adjMatrix,int** ans,int u,int old,int n){
    for (int i=0; i<n; i++) {
            if(adjMatrix[u][i]==1 && i!=old){
                ans[count]=i+1;
                // printf("ans[%d] = %d\n",count,ans[count]);
                count+=1;
                checkPath2(adjMatrix,ans,i,u,n);
            }

       }

}




int main()
{
    int n,e,n1,n2,p=0;
    scanf("%d",&n);
    int** adjMatrix = createGraph(n);
    int** ans=createList(100);
    scanf("%d",&e);
    for(int i=0;i<e;i++){
        scanf("%d %d",&n1,&n2);
        addEdge(adjMatrix,n1,n2);
    }
    scanf("%d %d",&n1,&n2);

    checkPath(adjMatrix,ans,n1,n2,n);

    for(int i=0;i<100;i++){
        if(ans[i]==n2+1){
            p+=1;
        }
    }
    if(p>=1){
        printf("True");
    }
    else{
        printf("False");
    }
}