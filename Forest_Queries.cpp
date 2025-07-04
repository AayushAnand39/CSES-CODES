#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<char>> a(n,vector<char>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    vector<vector<int>> temp(n,vector<int>(n,0));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            temp[i][j] = (a[i][j]=='*')?1:0;
            if (i>0) temp[i][j]+=temp[i-1][j];
            if (j>0) temp[i][j]+=temp[i][j-1];
            if (i>0 && j>0) temp[i][j]-=temp[i-1][j-1];
        }
    }
    for (int i=0;i<q;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--;
        x2--;
        y1--;
        y2--;
        int x = temp[x2][y2];
        if (x1>0) x-=temp[x1-1][y2];
        if (y1>0) x-=temp[x2][y1-1];
        if (x1>0 && y1>0) x+=temp[x1-1][y1-1];
        cout<<x<<endl;
    }
}
