#include<bits/stdc++.h>
using namespace std;

void printPath(int dest, vector<long long> &parent) {
    if (parent[dest] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    stack<int> path;
    for (int i=dest;i!=-1;i=parent[i]) path.push(i);
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<long long>> adj(n+1);
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<long long> dist(n+1,1e18), parent(n+1,-1);
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    pq.push({0,1});
    dist[1] = 0;
    while(!pq.empty()){
        long long d = pq.top().first;
        long long node = pq.top().second;
        pq.pop();
        if (d>dist[node]) continue;
        for (auto x:adj[node]){
            if ((d+1)<dist[x]){
                dist[x] = d+1;
                parent[x] = node;
                pq.push({dist[x],x});
            }
        }
    }
    if (dist[n]==1e18) cout<<"IMPOSSIBLE"<<endl;
    else{
        cout<<dist[n]+1<<endl;
        printPath(n,parent);
    }
}