#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    for (int i=0;i<m;i++) cin>>a[i];
    set<int> s;
    s.insert(0);
    s.insert(n);
    map<int,int> mp;
    mp[n]++;
    for (int i=0;i<m;i++){
        auto it1 = s.lower_bound(a[i]);
        auto it2 = it1;
        it1--;
        // cout<<*prev(it1)<<" "<<*it2<<endl;
        mp[*it2-*it1]--;
        if (mp[*it2-*it1]==0) mp.erase(*it2-*it1);
        mp[a[i]-*it1]++;
        mp[*it2-a[i]]++;
        s.insert(a[i]);
        // for (auto x:s) cout<<x<<" ";
        // cout<<endl;
        cout<<prev(mp.end())->first<<" ";
    }
    cout<<endl;
}