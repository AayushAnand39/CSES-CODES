#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    long long res = a[0];
    long long maxVal = a[0];
    for (int i=1;i<n;i++){
        maxVal = max(maxVal+a[i],a[i]);
        res = max(res,maxVal);
    }
    cout<<res<<endl;
}