#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *left, *right;
};

struct node *newNode(int item) {
  struct node *temp = new struct node;
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}


struct node *insert(struct node *node, int key) {
  if (node == NULL) return newNode(key);
  
//   cout <<"------"<< key <<" " << node->data << endl; 
  if (key < node->data){
    node->left = insert(node->left, key);
  }
  else{
    node->right = insert(node->right, key);}
  return node;
}

bool checkHeightBalance(struct node *root, int *height) {
  int leftHeight = 0, rightHeight = 0;
  int l = 0, r = 0;

  if (root == NULL) {
    *height = 0;
    return 1;
  }
  l = checkHeightBalance(root->left, &leftHeight);
  r = checkHeightBalance(root->right, &rightHeight);

  *height = (leftHeight > rightHeight ? leftHeight : rightHeight)+1 ;
//   cout<<" R "<< r<<" L "<<l<<endl;
//   cout<< rightHeight<<" , "<<leftHeight;
//   cout<<" Right - Left = "<<rightHeight-leftHeight<<endl;
//   cout<<" left - right = "<<leftHeight-rightHeight<<endl;
  if (((leftHeight-1) - rightHeight >=2) || ((rightHeight-1) - leftHeight>=2)){
    return 0;}
  else{
   return l||r;}
}


// Driver code
int main()
{
    int r,n,height=0;
    cin >> r;
    if(r==0){
        cout<< "empty tree";
    }
  else{
     struct node *root = newNode(r);
    while(1){
        cin >> n;
        if(n==0){break;}
        root = insert(root,n);
    }
    if(checkHeightBalance(root,&height)){
      cout<<"This tree has AVL property";
    }
    else{
    cout<<"This tree doesn't have AVL property";
    }

  }
//   struct node *root = newNode(r);
//   root = insert(root, 7);
//   root = insert(root, 6);
//   root = insert(root, 12);
//   root = insert(root, 4);
//   root = insert(root, 5);
//   root = insert(root,13);
//   root = insert(root,26);

//   int ans=checkHeightBalance(root,&height);
//   cout<<ans<<endl;

 
}