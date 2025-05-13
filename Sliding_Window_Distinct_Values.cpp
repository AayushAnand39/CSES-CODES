#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    unordered_map<int,int> mp;
    for (int i=0;i<k;i++) mp[a[i]]++;
    cout<<mp.size()<<" ";
    for (int i=k;i<n;i++){
        mp[a[i]]++;
        mp[a[i-k]]--;
        if (mp[a[i-k]]==0) mp.erase(a[i-k]);
        cout<<mp.size()<<" ";
    }
    cout<<endl;
}