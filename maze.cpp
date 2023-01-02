#include <iostream>
#include <list>
using namespace std;
int count=0;
class Graph
{
    int V; 
    list<int> *adj; 
public:
    Graph(int V); 
    void addEdge(int v, int w); 
    int checkPath(int s,int d); 
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w); 
    adj[w].push_back(v); 
}



int Graph::checkPath(int s,int d)
{
    
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    int u;
    while(!queue.empty()){
        u = queue.front();
        queue.pop_front();
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            if(*i==d){
                count=count+1;
            }

            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
   return count;
}



int main(){
    int v=21;
    int p=0;
    Graph graph(v);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(3,6);
    graph.addEdge(2,7);
    graph.addEdge(7,8);
    graph.addEdge(7,9);
    graph.addEdge(9,10);
    graph.addEdge(9,13);
    graph.addEdge(10,11);
    graph.addEdge(10,12);
    graph.addEdge(13,14);
    graph.addEdge(14,15);
    graph.addEdge(15,16);
    graph.addEdge(15,17);
    graph.addEdge(17,18);
    graph.addEdge(17,19);
    graph.addEdge(17,20);
    p=graph.checkPath(0,2);
    if(p>=1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}