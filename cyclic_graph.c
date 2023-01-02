#include<stdio.h>
#include<stdlib.h>

int** createGraph(const int n) {
    int** adjMatrix = malloc(sizeof(int*)*n);
    for (int i=0; i<n; i++) {
        adjMatrix[i] = malloc(sizeof(int)*n);
        for (int j=0; j<n; j++) 
            adjMatrix[i][j] = 0;
    }
    return adjMatrix;
}

void addEdge(int** adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;
}

void printGraph(int** adjMatrix, int n)
{
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
    printf("\n");
    }
}


int main()
{
    int n,e,n1,n2,check=0,p=0;
    scanf("%d",&n);
    int** adjMatrix = createGraph(n);
    scanf("%d",&e);
    for(int i=0;i<e;i++){
        scanf("%d %d",&n1,&n2);
        addEdge(adjMatrix,n1,n2);
    }
    printGraph(adjMatrix, n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adjMatrix[i][j]==1){
                check+=1;
            }
        }
        if(check==0){
            p+=1;
        }
        check=0;
    }
    // printf("%d",p);
    if(p>=1){
        printf("Graph doesn't contain cycle");
    }
    else{
        printf("Graph contains cycle");
    }

}