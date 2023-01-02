#include <iostream>
using namespace std;
int sum=0;
struct node
{
    string key;
    int memory;
    struct node* parent;
    struct node* leftChild;
    struct node* rightSibling;
};

struct node* createNode(string key, struct node* parent,int memory) {
    struct node *node = new struct node;
    node->key = key;
    node->memory = memory;
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

int depth(struct node* node)
{
    int depth = 0;
    while(node->parent != NULL) {
        depth+=node->memory;
        node = node->parent;
    }
    return depth;
}

bool isInternal(struct node *node) {
    if (node->leftChild != NULL) {
        return true;
    } else {
        return false;
    }
}

void postOrder(struct node* node)
{
    sum += node->memory;
    struct node *child = node->leftChild;
    while(child!=NULL){
        postOrder(child);
        child = child->rightSibling;
    }
 
    

}



int main()
{
    struct node *node[100];
    node[1] = createNode("/user/rt/courses/", NULL , 1);
    node[2] = createNode("cs016/", node[1] ,2 );
    node[3] = createNode("cs252/", node[1] ,1 );
    node[4] = createNode("grades/", node[2] ,8 );
    node[5] = createNode("homeworks/",node[2],1);
    node[6] = createNode("programs/",node[2],1);
    node[7] = createNode("hw1",node[5],3);
    node[8] = createNode("hw2",node[5],2);
    node[9] = createNode("hw3",node[5],4);
    node[10] = createNode("pr1",node[6],57);
    node[11] = createNode("pr2",node[6],97);
    node[12] = createNode("pr3",node[6],74);
    node[13] = createNode("projects/", node[3] ,1);
    node[14]= createNode("grades", node[3],3);
    node[15] = createNode("papers/",node[13],1);
    node[16] = createNode("demos/",node[13],1);
    node[17] = createNode("buylow",node[15],26);
    node[18] = createNode("sellhigh",node[15],55);
    node[19] = createNode("market",node[16],4786);

    for(int i=1; i<=19 ;i=i+1){
        postOrder(node[i]);
        cout << node[i]->key << " : " << sum <<" K"<<endl;
        sum =0 ;
    }
    // cout << sum;

}