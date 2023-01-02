#include <iostream>
using namespace std;
int sum=0;
string path[100];
int c=0;
struct node
{
    string key;
    struct node* parent;
    struct node* leftChild;
    struct node* rightSibling;
};
struct node* createNode(string key, struct node* parent) {
    struct node* node = (struct node*)malloc(sizeof(struct node));

    node->key = key;
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

void travel(struct node* node,string checkFile)
{   
    if (node == NULL)
        return;
    if (checkFile == node->key){
        sum++;
    }
    travel(node->leftChild,checkFile);
    travel(node->rightSibling,checkFile);
}

int isRoot(struct node* node)
{
    if(node->parent == NULL)
       return 1;
    else
       return 0;
}

void getParent(struct node* node)
{       
    if(isRoot(node->parent)){
    //   cout<< "The end";
       return;
    }
    path[c]= node->parent->key;
    // cout<<"Parent :"<<node->parent->key<<endl;
    // cout<<"Parent :"<<path[c]<<endl;
    c++;
    getParent(node->parent);
    
    
}

int main()
{
    struct node* node[100];
    int count=0;
    string parent;
    string child;
    string check;
    node[0]= createNode("/", NULL);
    // node[1]= createNode("a",node[0]);

for(int i=1; ;i++){
        cin >> parent;
        // cout<<"Parent : "<< parent<< endl;
        if(parent=="<`~`?>" ){
            break;
        }
        cin >> child;
        // cout<<"Child : "<<child<< endl;
        // cout<<"i = "<<i<<endl;
        for(int j=0;j<i;j++){
            
            // cout<< "j = " << j << " : " << node[j]->key<<endl;
            if(parent==node[j]->key){
                node[i]= createNode(child,node[j]);
                count=count+1;
            }
            
        }
        
    }
    cin >> check;
    for(int i=1; i<=count ;i++){
        travel(node[i],check);
        // cout<< sum;
    }
    // cout<<count<<endl;
    if(check=="/"){
        printf("/");
    }
    else if(sum>=1){
      
      for(int j=1;j<=count;j++){
          if(node[j]->key==check){
                //  cout<<check<<endl;
                //  cout<<j<<endl;
                getParent(node[j]);              
          }
      }
    //   cout<< c<<endl;
    //   cout<<path[c-1]<<endl;
    for(int i=c-1 ; i>=0 ; i=i-1){
            cout<< "/" << path[i];
      }
      cout<<"/"<<check;
    }
    else{
        cout<<"(╯°□°）╯︵ ┻━┻ - Not found, Alas!!!"<<endl;
        cout<<"┬─┬ /( ゜-゜/) - Calm down bro.";
    }




}