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
    string s;
    cin>>s;
    vector<long long> a(1000001);
    a[0]=1;
    a[1]=1;
    for (long long i=2;i<=1000000;i++){
        a[i] = (a[i-1]*i)%mod;
    }
    unordered_map<char,int> mp;
    for (int i=0;i<s.length();i++) mp[s[i]]++;
    long long res = a[s.length()];
    for (auto x:mp){
        if (x.second>1) res = (res*exp(a[x.second],mod-2))%mod;
    }
    cout<<res<<endl;
}