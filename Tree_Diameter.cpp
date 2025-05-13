#include<bits/stdc++.h>
using namespace std;

void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& dist){
    for (int v:adj[u]){
        if (v!=p){
            dist[v] = dist[u] + 1;
            dfs(v,u,adj,dist);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for (int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n+1);
    int last = 0;
    dfs(1,0,adj,dist);
    for (int i=1;i<=n;i++){
        if (dist[i]>dist[last]){
            last=i;
        }
    }
    dist[last] = 0;
    dfs(last,0,adj,dist);
    for (int i=1;i<=n;i++){
        if (dist[i]>dist[last]){
            last=i;
        }
    }
    cout<<dist[last]<<endl;
}