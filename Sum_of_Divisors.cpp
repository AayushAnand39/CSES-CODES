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
    long long s = 0;
    long long sq = sqrt(n);
    long long inv = exp(2, mod-2);
    for (long long i=1;i<=sq;i++){
        long long x = (n/i-n/(i+1))%mod;
        long long r = n/i, l = n/(i+1)+1;
        s = (s+x*((l+r)%mod)%mod*inv%mod*i%mod)%mod;
    }
    for (long long i=1;i<=n/(sq+1);i++){
        s = (s+n/i*i)%mod;
    }
    cout<<s<<endl;
}