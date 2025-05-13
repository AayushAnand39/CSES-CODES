#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    vector<int> vec(n,0);
    for (int i=0;i<n;i++){
        for (int j=0;j<a[i].length();j++){
            if (a[i][j]=='1') vec[i]+=(1<<j);
        }
    }
    int ans = 32;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            ans = min(ans,(int)__builtin_popcount(vec[i]^vec[j]));
        }
    }
    cout<<ans<<endl;
}