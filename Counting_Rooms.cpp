#include<bits/stdc++.h>
using namespace std;

void dfs(int r, int c, int delrow[], int delcol[], vector<vector<char>>& a, vector<vector<int>>& vis){
    vis[r][c] = 1;
    for (int i=0;i<4;i++){
        int nr = r+delrow[i];
        int nc = c+delcol[i];
        if (nr>=0 && nr<a.size() && nc>=0 && nc<a[0].size() && a[nr][nc]=='.' && vis[nr][nc]==0){
            vis[nr][nc]=1;
            dfs(nr,nc,delrow,delcol,a,vis);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    vector<vector<int>> vis(n,vector<int>(m,0));
    int count = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j]=='.' && vis[i][j]==0){
                count++;
                dfs(i,j,delrow,delcol,a,vis);
            }
        }
    }
    cout<<count<<endl;
}