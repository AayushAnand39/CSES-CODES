#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(int n, vector<vector<int>>& adj, vector<int>& answer){
    queue<int> q;
    for (int i=1;i<=n;i++){
        if (answer[i]!=-1) continue;
        answer[i]=1;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for (auto x:adj[node]){
                if (answer[x]==-1){
                    answer[x] = 1-answer[node];
                    q.push(x);
                }
                else if (answer[x]==answer[node]) return false;
            }
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> answer(n+1,-1);
    if (!checkBipartite(n,adj,answer)) cout<<"IMPOSSIBLE"<<endl;
    else{
        for (int i=1;i<=n;i++) cout<<answer[i]+1<<" ";
        cout<<endl;
    }
}