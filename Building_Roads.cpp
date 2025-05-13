#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent, rank, size;
public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for (int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int find(int node){
        if (node==parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulpU = find(u);
        int ulpV = find(v);
        if (ulpU==ulpV) return;
        if (rank[ulpU]<rank[ulpV]){
            parent[ulpU] = ulpV;
        }
        else if (rank[ulpV]<rank[ulpU]){
            parent[ulpV] = ulpU;
            rank[ulpU]++;
        }
    }
    void unionBySize(int u, int v){
        int ulpU = find(u);
        int ulpV = find(v);
        if (ulpU==ulpV) return;
        if (size[ulpU]<size[ulpV]){
            parent[ulpU] = ulpV;
            size[ulpV] += size[ulpU];
        }
        else{
            parent[ulpV] = ulpU;
            size[ulpU] += size[ulpV];
        }
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    DSU ds(n+1);
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        ds.unionBySize(u,v);
    }
    vector<pair<int,int>> answer;
    for (int i=1;i<n;i++){
        if (ds.find(i)!=ds.find(i+1)){
            answer.push_back({i,i+1});
            ds.unionBySize(i,i+1);
        }
    }
    cout<<answer.size()<<endl;
    for (auto x:answer) cout<<x.first<<" "<<x.second<<endl;
}