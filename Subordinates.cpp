#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(2e5+1);
vector<int> temp(2e5+1);

void dfs(int u){
    temp[u] = 1;
    for (int v:adj[u]){
        dfs(v);
        temp[u]+=temp[v];
    }
}

int main(){
    int n;
    cin>>n;
    for (int i=2;i<=n;i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    dfs(1);
    for (int i=1;i<=n;i++){
        cout<<temp[i]-1<<" ";
    }
    cout<<endl;
}