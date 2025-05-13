#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;

const long long maxn = 1e6+6;
long long dp[maxn][3];

int main(){
    long long t;
    cin>>t;
    dp[1][1] = dp[1][2] = 1;
    for (long long i=2;i<=maxn;i++){
        dp[i][1] = (dp[i-1][1]*4%mod+dp[i-1][2])%mod;
        dp[i][2] = (dp[i-1][1]+dp[i-1][2]*2%mod)%mod;
    }
    while(t--){
        long long n;
        cin>>n;
        cout<<(dp[n][1]+dp[n][2])%mod<<endl;
    }
}