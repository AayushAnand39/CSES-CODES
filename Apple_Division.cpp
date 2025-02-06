#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> a(n);
    for (long long i=0;i<n;i++) cin>>a[i];
    long long totSum = accumulate(a.begin(),a.end(),0LL);
    long long minVal = LLONG_MAX;
    for (long long i=0;i<(1LL<<n);i++){
        long long x = i;
        long long sum = 0;
        int j=0;
        while(x>0){
            if (x%2==1) sum+=a[j];
            j++;
            x/=2;
        }
        minVal = min(minVal,abs(totSum-2*sum));
    }
    cout<<minVal<<endl;
}