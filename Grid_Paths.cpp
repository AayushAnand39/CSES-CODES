#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, int k, string& s, vector<vector<int>>& vis){
    if (i<0 || i>=7 || j<0 || j>=7 || vis[i][j]) return 0;
    if (k==s.length()){
        if (i==6 && j==0) return 1;
        else return 0;
    }
    int path = 0;
    if (s[k]=='?') {
        if (vis[i+1][j]==0) path += f(i+1,j,k+1,s,vis);
        if (vis[i][j+1]==0) path += f(i,j+1,k+1,s,vis);
        if (vis[i-1][j]==0) path += f(i-1,j,k+1,s,vis);
        if (vis[i][j-1]==0) path += f(i,j-1,k+1,s,vis);
    }
    int path1 = 0;
    if (s[k]=='U') {
        if (vis[i-1][j]==0) path1 += f(i-1,j,k+1,s,vis);
    }
    int path2 = 0;
    if (s[k]=='D') {
        if (vis[i+1][j]==0) path2 += f(i+1,j,k+1,s,vis);
    }
    int path3 = 0;
    if (s[k]=='L') {
        if (vis[i][j-1]==0) path3 += f(i,j-1,k+1,s,vis);
    }
    int path4 = 0;
    if (s[k]=='R') {
        if (vis[i][j+1]==0) path4 += f(i,j+1,k+1,s,vis);
    }
    return (path+path1+path2+path3+path4);
}

int main(){
    string s;
    cin>>s;
    vector<vector<int>> vis(7,vector<int>(7,0));
    cout<<f(0,0,0,s,vis)<<endl;
}