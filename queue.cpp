#include <iostream>
using namespace std;
# define SIZE 100
string arr[SIZE];
int rear = - 1;
int front = - 1;

void enqueue(string name){
    if (rear==SIZE-1){
        //cout<<"Queue is full"<<endl;
    }
    else{
        rear++;
        arr[rear]=name;
        if(front ==-1){
            front=0;
        }
    } 
}
string dequeue()
{
    string data;
    if (front == - 1 ){
        return "0";
    }
    
    data =arr[front];
    if(front==rear){
        front=rear=-1;
    }
    else{
        front=front+1;
    }
    
    return data;
} 

void peek()
{
    if (front != - 1){
       cout<< arr[front]<<endl;
    }
} 

void empty(){
    if(front==-1 && rear==-1){
       cout<<"EmPTy"<<endl;
    }
    else{
       cout<<"nOT EmpTY"<<endl;
    }
}

int main(){
    string ch,name,ans;
    while (1)
    {   
        cin>>ch;
        if(ch=="enqueue"){
            cin>>name;
            enqueue(name);
        }
        else if(ch=="dequeue"){
            ans=dequeue();
            if(ans!="0"){
                cout<<ans<<endl;
            }
        }
        else if(ch=="peek"){
            peek();
        }
        else if(ch=="empty?"){
            empty();
        }
        else if(ch=="exit"){
            break;
        }
        
    } 
}


 
