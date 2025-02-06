#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    vector<int> prev(x+1,0), curr(x+1,0);
    for (int j=0;j<=x;j++){
        if (j%a[0]==0) prev[j]=1;
    }
    for (int i=1;i<n;i++){
        for (int j=0;j<=x;j++){
            int case1 = prev[j];
            int case2 = 0;
            if (j>=a[i]) case2 = curr[j-a[i]];
            curr[j] = (case1+case2)%mod;
        }
        prev=curr;
    }
    cout<<prev[x]<<endl;
}