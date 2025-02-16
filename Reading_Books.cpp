#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    long long x = a[n-1];
    long long y = accumulate(a.begin(),a.end()-1,0LL);
    if (x<=y) cout<<x+y<<endl;
    else cout<<2*x<<endl;
}