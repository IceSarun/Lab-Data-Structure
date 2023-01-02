#include <iostream>
using namespace std;
struct node
{
    string key;
    int distance;
    struct node* parent;
    struct node* leftChild;
    struct node* rightSibling;
};
struct node* createNode(string key, struct node* parent,int distance) {
    struct node* node = (struct node*)malloc(sizeof(struct node));

    node->key = key;
    node->distance = distance;
    node->parent = parent;
    node->leftChild = NULL;
    node->rightSibling = NULL;

    if(node->parent != NULL) {
        if(node->parent->leftChild != NULL) {
            struct node* child = node->parent->leftChild;
            while(child->rightSibling != NULL) {
            child = child->rightSibling;
            }
        child->rightSibling = node;
    }
        else {
        node->parent->leftChild = node;
    }
}
    return node;
}

int isExternal(struct node* node)
{
    if(node->leftChild == NULL){
        return 1;
    }
    else{
        return 0;
    }

}

int depth(struct node* node)
{
    int depth = 0;
    while(node->parent != NULL) {
        depth+=node->distance;
        node = node->parent;
    }
    return depth;
}

int main()
{
    double sum=0;
    struct node* node[100];
    int count=0,in,dis;
    string parent;
    string child;
    node[0]= createNode("0", NULL,0);

    // node[1]= createNode("a",node[0],2);
    // node[2]= createNode("b",node[0],5);
    // node[3]= createNode("c",node[1],3);
    // node[4]= createNode("d",node[3],4);
    // node[5]= createNode("u",node[1],1);
   cin >> in;
//   cout << in;
    for(int i=1; i<=in ;i++){
        cin >> parent;
        cin >> child;
        cin >> dis;
        // cout<< parent<<endl;
        // cout<< node[i-1];
        for(int j=0;j<i;j++){
            // cout<< node[j]->key<<endl;
            if(parent==node[j]->key){
                node[i]= createNode(child,node[j],dis);}
         }
    }

    // struct node* node1 = createNode("1", NULL,0);   
    // struct node* node2 =createNode("2", node1,0);
    // struct node* node3 =createNode("3", node1,0);
    // struct node* node4 =createNode("4", node2,0);
    // printf("%d",isExternal(node[1]));

    for(int i=1; i<=in ;i++){
        if(isExternal(node[i])){
            sum+=depth(node[i]);
            // printf("%d %d\n",i,depth(node[i]));
            count++;
        }
    }
    if(count>0){
        sum=sum/count;}
    else if(count==0){
        sum=0;
    }
    printf("%.2lf",sum);
    





}