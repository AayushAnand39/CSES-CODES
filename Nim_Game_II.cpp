#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n);
        for (int i=0;i<n;i++) cin>>a[i];
        for (int i=0;i<n;i++) a[i]%=4;
        long long x = 0;
        for (int i=0;i<n;i++) x^=a[i];
        if (x!=0) cout<<"first"<<endl;
        else cout<<"second"<<endl;
    }
}