#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;

long long dp[501][62626];
long long f(long long i, long long n){
    if (n<0) return 0;
    if (n==0) return 1;
    if (i==0) return 0;
    if (dp[i][n]!=-1) return dp[i][n];
    long long case1 = f(i-1,n);
    long long case2 = f(i-1,n-i);
    return dp[i][n] = (case1+case2)%mod;
}

int main(){
    long long n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    long long x = n*(n+1)/2;
    if (x%2!=0) cout<<0<<endl;
    else cout<<1LL*f(n,x/2)*((mod+1)/2)%mod<<endl;
}