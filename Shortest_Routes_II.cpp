#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>> dist(n+1,vector<long long>(n+1,LLONG_MAX));
    for (int i=1;i<=n;i++) dist[i][i] = 0;
    for (int i=0;i<m;i++){
        long long x,y,z;
        cin>>x>>y>>z;
        dist[x][y] = min(dist[x][y],z);
        dist[y][x] = min(dist[y][x],z);
    }
    for (int k=1;k<=n;k++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (dist[i][k]<LLONG_MAX && dist[k][j]<LLONG_MAX){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    for (int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        if (dist[x][y]==LLONG_MAX) cout<<-1<<endl;
        else cout<<dist[x][y]<<endl;
    }
}