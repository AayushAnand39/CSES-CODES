#include<bits/stdc++.h>
using namespace std;

vector<long long> findPath(int destX, int destY, vector<long long>& parent, int n){
    if (parent[destX+n*destY] == -1){
        cout<<"IMPOSSIBLE"<<endl;
        return {};
    }
    vector<long long> answer;
    stack<long long> path;
    for (int i=parent[destX+n*destY];i!=-1;i=parent[i]) path.push(i);
    while(!path.empty()){
        answer.push_back(path.top());
        path.pop();
    }
    return answer;
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
    vector<long long> dist(n*m,1e18);
    int sx=-1, sy=-1, fx=-1, fy=-1;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j]=='A'){
                sx=i;
                sy=j;
            }
            if (a[i][j]=='B'){
                fx=i;
                fy=j;
            }
        }
    }
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    queue<tuple<int,int,int>> q;
    q.push({sx,sy,0});
    dist[sx+n*sy]=0;
    vector<long long> parent(n*m,-1);
    while(!q.empty()){
        auto [u,v,length] = q.front();
        q.pop();
        for (int i=0;i<4;i++){
            int nu = u+dr[i];
            int nv = v+dc[i];
            if (nu>=0 && nu<n && nv>=0 && nv<m && a[nu][nv]!='#'){
                long long len = length+1;
                if (len < dist[nu+n*nv]){
                    dist[nu+n*nv] = len;
                    parent[nu+n*nv] = (u+n*v);
                    q.push({nu,nv,len}); 
                }
            }
        }
    }
    if (dist[fx+n*fy]==1e18) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl<<dist[fx+n*fy]<<endl;
        vector<long long> answer = findPath(fx,fy,parent,n);
        string s;

        for (int i=0;i<answer.size()-1;i++){
            if ((answer[i]-answer[i+1])==n) s+='L';
            else if ((answer[i]-answer[i+1])==-n) s+='R';
            else if ((answer[i]-answer[i+1])==1) s+='U';
            else if ((answer[i]-answer[i+1])==-1) s+='D';
        }
        if (((fx+n*fy)-answer.back())==-n) s+='L';
        else if (((fx+n*fy)-answer.back())==n) s+='R';
        else if (((fx+n*fy)-answer.back())==-1) s+='U';
        else if (((fx+n*fy)-answer.back())==1) s+='D';
        cout<<s<<endl;
    }
}