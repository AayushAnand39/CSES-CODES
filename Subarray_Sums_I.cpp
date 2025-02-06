#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,x;
    cin>>n>>x;
    vector<long long> a(n);
    for (long long i=0;i<n;i++) cin>>a[i];
    vector<long long> prefix(n);
    prefix[0] = a[0];
    for (long long i=1;i<n;i++) prefix[i] = prefix[i-1]+a[i];
    long long count = 0;
    for (long long i=0;i<n;i++){
        long long y = prefix[i]-x;
        if (y==0) count++;
        else if (y>0){
            long long z = lower_bound(prefix.begin(),prefix.end(),y)-prefix.begin();
            if (prefix[z]==y && i!=z) count++;
        }
    }
    cout<<count<<endl;
}