#include <iostream>
// #include <string>
using namespace std;

int main(){
    string food[100];
    string quest;
    int list,i=0;
    cin >> quest;
    if(quest!="exit"){
        for(;quest!="exit";){
            if(quest=="add"){
                cin >> food[i];
                i++;
            }

            else if(quest=="del"){
                cin >> list;
                list=list-1;
                for(int z=0;z<i;z++){
                    if(list==z){
                        for(int j=z+1;j<i;j++){
                            food[z]=food[j];
                            z++;
                        }
                        i=i-1;
                        break;
                    }
                }
            }
            else if(quest=="show"){
                cout<<"<< Menu >>"<<endl;
                for(int j=0;j<i;j++){
                    cout<<j+1<<". "<< food[j]<<endl;
                }
            }

            cin >> quest;
    }

    }
    cout<< "<< Menu >>"<<endl;
    for(int j=0;j<i;j++){
        cout<<j+1<<". "<< food[j]<<endl;
    }
    



}