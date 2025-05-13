#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for (int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    sort(a.begin(),a.end());
    long long count = 0;
    long long total = 0;
    for (int i=0;i<n;i++){
        count+=a[i].first;
        total+=(a[i].second-count);
    }
    cout<<total<<endl;
}