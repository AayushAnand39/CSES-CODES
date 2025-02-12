#include<bits/stdc++.h>
using namespace std;

int dp[5001][5001];
int f(int i, int j, string& s, string& t){
    if (i<0) return j+1;
    if (j<0) return i+1;
    if (dp[i][j]!=-1) return dp[i][j];
    if (s[i]==t[j]) return dp[i][j] = 0+f(i-1,j-1,s,t);
    else return dp[i][j] = 1+min({f(i-1,j,s,t),f(i,j-1,s,t),f(i-1,j-1,s,t)});
}

int main(){
    memset(dp,-1,sizeof(dp));
    string s,t;
    cin>>s>>t;
    cout<<f(s.length()-1,t.length()-1,s,t)<<endl;
}