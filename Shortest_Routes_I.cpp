#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    vector<vector<pair<long long,long long>>> adj(n+1);
    for (long long i=0;i<m;i++){
        long long x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
    }
    vector<long long> dist(n+1,1e18);
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    pq.push({0,1});
    dist[1] = 0;
    while(!pq.empty()){
        long long d = pq.top().first;
        long long node = pq.top().second;
        pq.pop();
        if (d>dist[node]) continue;
        for (auto x:adj[node]){
            if (d+x.second<dist[x.first]){
                dist[x.first] = d+x.second;
                pq.push({dist[x.first],x.first});
            }
        }
    }
    for (long long i=1;i<=n;i++) cout<<dist[i]<<" ";
    cout<<endl;
}