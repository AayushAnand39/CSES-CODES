#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        if (n>m){
            long long res = (n-1)*(n-1);
            long long x = 0;
            if (n%2!=0) x=m;
            else x = 2*n-m;
            cout<<res+x<<endl;
        }
        else{
            long long res = (m-1)*(m-1);
            long long x = 0;
            if (m%2==0) x=n;
            else x = 2*m-n;
            cout<<res+x<<endl;
        }
    }
}