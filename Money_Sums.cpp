#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int x = accumulate(a.begin(),a.end(),0);
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    dp[0][0] = 1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=x;j++){
            dp[i][j] = dp[i-1][j];
            if (j>=a[i-1] && dp[i-1][j-a[i-1]]==1){
                dp[i][j]=1;
            }
        }
    }
    vector<int> answer;
    for (int i=1;i<=x;i++){
        if (dp[n][i]){
            answer.push_back(i);
        }
    }
    cout<<answer.size()<<endl;
    for (auto x:answer) cout<<x<<" ";
    cout<<endl;
}