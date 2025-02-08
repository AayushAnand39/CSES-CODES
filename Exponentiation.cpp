#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

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
    for (int i=0;i<n;i++){
        long long x,y;
        cin>>x>>y;
        cout<<exp(x,y)%mod<<endl;
    }
}