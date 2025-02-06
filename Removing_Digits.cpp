#include<bits/stdc++.h>
using namespace std;

int dp[1000001];
int f(int x){
    if (x==0) return 0;
    string s = to_string(x);
    if (dp[x]!=-1) return dp[x];
    int count = INT_MAX;
    for (int i=0;i<s.length();i++){
        if (s[i]=='0') continue;
        int y = x-(s[i]-'0');
        count=min(count,1+f(y));
    }
    return dp[x] = count;
}

int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<f(n)<<endl;
}