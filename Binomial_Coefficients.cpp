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
    int n;
    cin>>n;
    vector<long long> a(1000001);
    a[0]=1;
    a[1]=1;
    for (long long i=2;i<=1000000;i++){
        a[i] = (a[i-1]*i)%mod;
    }
    for (int i=0;i<n;i++){
        long long x,y;
        cin>>x>>y;
        if (y>x) cout<<0<<endl;
        else{
            int res = (a[x]*exp(a[y],mod-2))%mod;
            res = (res*exp(a[x-y],mod-2))%mod;
            cout<<res<<endl;
        }
    }
}