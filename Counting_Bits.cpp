#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll f(ll n) {
    if(n==0) return 0;
    ll x = 0;
    while((1LL<<(x+1))<=n) x++;
    ll p = 1LL<<x; 
    ll y = x*(p>>1);
    ll z = n-p+1;
    ll r = f(n-p);
    return y+z+r;
}

int main(){
    long long n;
    cin>>n;
    cout<<f(n)<<endl;
}
