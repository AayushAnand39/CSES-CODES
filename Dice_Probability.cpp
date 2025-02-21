#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<vector<double>> dp(n+1,vector<double>(6*n+1,0));
    dp[0][0]=1.0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=6*n;j++){
            for (int k=1;k<=6;k++){
                if ((j-k)>=0) dp[i][j]+=dp[i-1][j-k];
            }
            dp[i][j]/=6;
        }
    }
    double res = 0;
    for (int i=a;i<=b;i++){
        res+=1.0*dp[n][i];
    }
    cout<<fixed<<setprecision(6)<<res<<endl;
}