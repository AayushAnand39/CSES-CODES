#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long totalSum = 1LL*n*(n+1)/2;
    if (totalSum%2!=0) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        vector<int> a,b;
        vector<int> vis(n+1,0);
        long long sum = 0;
        long long maxVal = n;
        while(sum<totalSum/2){
            long long rem = totalSum/2-sum;
            if (rem>maxVal){
                a.push_back(maxVal);
                vis[maxVal]=1;
                sum+=maxVal;
                maxVal--;
            }
            else{
                a.push_back(rem);
                vis[rem]=1;
                sum=totalSum/2;
            }
        }
        for (int i=1;i<=n;i++){
            if (vis[i]==0) b.push_back(i);
        }
        cout<<a.size()<<endl;
        for (auto x:a) cout<<x<<" ";
        cout<<endl;
        cout<<b.size()<<endl;
        for (auto x:b) cout<<x<<" ";
        cout<<endl;
    }
}