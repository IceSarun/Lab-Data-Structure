#include <bits/stdc++.h>
#include <queue>
using namespace std;

void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}
 

bool BFS(vector<int> adj[], int src, int dest, int v,
         int pred[], int dist[])
{

    priority_queue<int,vector<int>, greater<int>> queue;
 
    bool visited[v];
 

    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    visited[src] = true;
    dist[src] = 0;
    queue.push(src);

    while (!queue.empty()) {
        int u = queue.top();
        queue.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push(adj[u][i]);
 
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }
 
    return false;
}
 
void printShortestDistance(vector<int> adj[], int s,
                           int dest, int v)
{

    int pred[v], dist[v];
 
    if (BFS(adj, s, dest, v, pred, dist) == false) {
        cout << "404: Path not found :(";
        
    }
    else{
        vector<int> path;
        int crawl = dest;
        path.push_back(crawl);
        while (pred[crawl] != -1) {
            path.push_back(pred[crawl]);
            crawl = pred[crawl];
        }
 

        cout << "Shortest Distance: "
             << dist[dest]<< "\n";
 
        cout << "Path = ";
        for (int i = path.size() - 1; i >= 0; i--)
            if(i>0){
                cout << path[i] << " > ";}
            else{
                cout<< path[i]<<" :) ";
        }
}}
 

int main()
{

    int n,e ;
    int m,k;
    cin>>n;
    cin>>e;

    vector<int> adj[n];
    for(int i=0; i<e; i++){
        cin>>m;
        cin>>k;
        add_edge(adj, m, k);
    }


    int source , dest ;
    cin>>source;
    cin>>dest;
    printShortestDistance(adj, source, dest, n);
    return 0;
}
