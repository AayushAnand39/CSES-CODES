#include<bits/stdc++.h>
using namespace std;

int count1 = 0;
void dfs(int u, int x, vector<vector<int>>& adj, vector<int>& vis){
    for (int v:adj[u]){
        if (v!=x) dfs(v,u,adj,vis);
    }
    if (!vis[x] && !vis[u] && x!=0){
        vis[x] = vis[u] = 1;
        count1++;
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
    vector<int> vis(n+1,0);
    dfs(1,0,adj,vis);
    cout<<count1<<endl;
}