#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,x;
    cin>>n>>x;
    vector<long long> a(n);
    for (long long i=0;i<n;i++) cin>>a[i];
    map<long long, long long> mp;
    long long pre = 0, count = 0;
    for (int i=0;i<n;i++){
        pre+=a[i];
        if (pre==x) count++;
        if (mp.find(pre-x)!=mp.end()){
            count+=mp[pre-x];
        }
        mp[pre]++;
    }
    cout<<count<<endl;
}
