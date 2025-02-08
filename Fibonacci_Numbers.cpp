#include<bits/stdc++.h>
using namespace std;

map<long long, long long> mp;
const long long mod = 1000000007;

long long f(long long n){
    if (mp.count(n)) return mp[n];
    long long k = n/2;
    if (n%2==0) {
        return mp[n] = (f(k)*f(k) + f(k-1)*f(k-1))%mod;
    }
    else {
        return mp[n] = (f(k)*f(k+1) + f(k-1)*f(k))%mod;
    }
}

int main(){
    long long n;
    cin>>n;
    mp[0]=1, mp[1]=1;
    if (n==0) cout<<0<<endl;
    else cout<<f(n-1)<<endl;
}
