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

void Inorder(struct node *root) {
  if (root != NULL) {

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
  }
}


struct node *insert(struct node *node, int key) {
  if (node == NULL) return newNode(key);

  if (key < node->data){
    node->left = insert(node->left, key);
  }
  else{
    node->right = insert(node->right, key);}
  return node;
}
 

 void Postorder(struct node *root)
{
    if (!root) {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

void Preorder(struct node *root)
{
    if (!root) {
        return;
    }
    cout << root->data <<  " ";
    Preorder(root->left);
    Preorder(root->right);
}

int tree_height(struct node* root) {
    if (root == NULL) 
        return 0;
    else {
    
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
         
        if (left_height > right_height)
            return left_height+1 ;
        else
            return right_height+1 ;
    }
}


// Driver code
int main()
{
    int r,n;
    struct node *root = NULL;
    cin >> r;
    if(r==0){
        cout<< "empty tree";
    }
   else{
    root = insert(root,r);
    while(1){
        cin >> n;
        if(n==0){break;}
        root = insert(root,n);
    }
    cout<<"Height: "<<tree_height(root)-1<<endl;
    cout<<"Preorder: ";
    Preorder(root);
    cout<<endl;
    cout<<"Inorder: ";
    Inorder(root);
    cout<<endl;
    cout<<"Postorder: ";
    Postorder(root);
    cout<<endl;
  }
//   root = insert(root, 7);
//   root = insert(root, 4);
//   root = insert(root, 3);
//   root = insert(root, 6);
//   root = insert(root, 10);
//   root = insert(root, -2);
//   root = insert(root, 9);

  

}