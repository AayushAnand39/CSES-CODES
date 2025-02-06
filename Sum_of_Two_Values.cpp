#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    map<int,int> mp;
    for (int i=0;i<n;i++) mp[a[i]]=i;
    for (int i=0;i<n;i++){
        if (mp.find(x-a[i])!=mp.end()){
            if (i!=mp[x-a[i]]){
                cout<<i+1<<" "<<mp[x-a[i]]+1<<endl;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}