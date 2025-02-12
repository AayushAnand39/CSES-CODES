#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    long long res = 1;
    vector<long long> vec(n+1);
    for (int i=0;i<n;i++){
        vec[a[i]]=i;
    }
    for (int i=1;i<n;i++){
        if (vec[i+1]<vec[i]) res++;
    }
    cout<<res<<endl;
}