#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    vector<int> prev(x+1,1e9+1), curr(x+1,1e9+1);
    for (int j=0;j<=x;j++){
        if (j%a[0]==0) prev[j]=j/a[0];
    }
    for (int i=1;i<n;i++){
        for (int j=0;j<=x;j++){
            int case1 = prev[j];
            int case2 = 1e9+1;
            if (j>=a[i]) case2 = 1+curr[j-a[i]];
            curr[j] = min(case1,case2);
        }
        prev=curr;
    }
    if (prev[x]==(1e9+1)) cout<<-1<<endl;
    else cout<<prev[x]<<endl;
}