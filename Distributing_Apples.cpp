#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;

long long exp(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<long long> a(2000001);
    a[0]=1;
    a[1]=1;
    for (long long i=2;i<=2000000;i++){
        a[i] = (a[i-1]*i)%mod;
    }
    long long res = (a[n+m-1]*exp(a[n-1],mod-2))%mod;
    res = (res*exp(a[m],mod-2))%mod;
    cout<<res<<endl;
}