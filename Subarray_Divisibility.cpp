#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> a(n);
    for (long long i=0;i<n;i++) cin>>a[i];
    map<long long, long long> mp;
    mp[0]++;
    long long x=0, count=0;
    for (int i=0;i<n;i++){
        x = ((x+a[i])%n+n)%n;
        count+=mp[x];
        mp[x]++;
    }
    cout<<count<<endl;
}
