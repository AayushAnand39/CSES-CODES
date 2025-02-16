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
    long long n;
    cin>>n;
    if (n%2==1){
        cout<<0<<endl;
        return 0;
    }
    n/=2;
    vector<long long> a(2*n+1);
    a[0]=1;
    for (long long i=1;i<=2*n;i++){
        a[i] = (a[i-1]*i)%mod;
    }
    long long res = (a[2*n]*exp(a[n],mod-2))%mod;
    res = (res*exp(a[n],mod-2))%mod;
    res = (res*exp(n+1,mod-2))%mod;
    res%=mod;
    cout<<res<<endl;
}