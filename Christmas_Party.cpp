#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<long long> d(n+1);
    d[1]=0;
    d[2]=1;
    for (long long i=3;i<=n;i++){
        d[i] = (((d[i-1]+d[i-2])%mod)*(i-1))%mod;
    }
    cout<<d[n]<<endl;
}