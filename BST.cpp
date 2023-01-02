#include<bits/stdc++.h>
using namespace std;
int tree[100];
int ans[100];
int dee=0;

void root(int key) {
  if (tree[0] != '\0'){}
  else
    tree[0] = key;
}
 
void set_left(int key, int parent) {
  if (tree[parent] == '\0'){}
  else
    tree[(parent * 2) + 1] = key;
}
 
void set_right(int key, int parent) {
  if (tree[parent] == '\0'){}
  else
    tree[(parent * 2) + 2] = key;
}
 
void print_tree() {
  cout << "\n";
  for (int i = 1; i < 100; i++) {
    if (tree[i] != 0 ){
    //   cout << tree[i]<<" ";
      if(tree[(i-1)/2]<tree[i] && (i%2!=0)){
          dee+=1;
      }
      if(tree[(i-2)/2]>tree[i] && (i%2==0)){
          dee+=1;
      }
    }
  }
  if(dee>0){
      cout<<"This tree is illegal.";
  }
  else{
      cout<<"A binary search tree, this is.";
  }

}

 
// Driver Code
int main() {
  // root(0);
  // set_left(1,0);
  // set_right(2, 0);
  // set_left(3, 1);
  // set_right(4, 1);

  // for(int i=0;i<100;i++){
  //   tree[i]=0;
  // }

    int r, parent, child;
    int count=0,check=0,bst=0,a=0;
    string relate;
    cin >> r;
    root(r);
    for(int i=1; ;i+=1){
        cin >> parent;
        // cout<<"Parent : "<< parent<< endl;
        cin >> child;
        // cout<<"Child : "<<child<< endl;
        // cout<<"i = "<<i<<endl;
        // cout<<"PARENT "<<parent<<endl;
        cin >> relate;

        if(parent== 0 && child == 0 && relate=="end"){
            break;
        }
        for(int j=0;j<i;j+=1){
          if(tree[j]==child){
            cout<<"Not what I am looking for, I am afraid.";
            check+=1;
            break;
          }
          
          if(tree[j]==parent){
            // cout<< j <<endl;
            // cout<< (j*2)+1 <<endl;
            // cout<<(j*2)+2<<endl;
            if(tree[(j*2)+1] != NULL && relate=="L" ){
              cout<<"Not what I am looking for, I am afraid.";
              check+=1;
              break;
            }
            if(tree[(j*2)+2] != NULL && relate=="R" ){
              cout<<"Not what I am looking for, I am afraid.";
              check+=1;
              break;
            }
          }
        }
        if(check>0){
          break;
        }
        count+=1;
        for(int j=0;j<i;j+=1){
            if(parent==tree[j]){
                if(relate=="R"){
                    set_right(child,j);
                }
                else if(relate=="L"){
                    set_left(child,j);
                }
            }
        }
    }
    // cout << count << check;

    if(count==0 && check==0){
        cout<< "This tree is lonely, give them a hug.";
    }
    else if(count>0 && check==0){
      print_tree();
        
          
    }
    
    
   
    

}