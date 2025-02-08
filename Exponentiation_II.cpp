#include<bits/stdc++.h>
using namespace std;

long long exp(long long a, long long b, long long m) {
    if (a==0 && b==0) return 1;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a)%m;
        a = (a * a)%m;
        b >>= 1;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        long long x,y,z;
        cin>>x>>y>>z;
        long long m = 1e9+7;
        long long a = exp(y,z,m-1);
        cout<<exp(x,a,m)<<endl;
    }
}