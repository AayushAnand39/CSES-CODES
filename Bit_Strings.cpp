#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    int res = 1;
    for (int i=1;i<=n;i++){
        res = (res*2)%mod;
    }
    cout<<res<<endl;
}