#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> a(n);
    for (long long i=0;i<n;i++) cin>>a[i];
    long long x = *max_element(a.begin(),a.end());
    vector<long long> freq(1000005,0);
    for (long long i=0;i<n;i++) freq[a[i]]++;
    for (long long i=x;i>=1;i--){
        long long count = 0;
        for (long long j=i;j<=x;j+=i){
            count+=freq[j];
            if (count>1){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    return 0;
}
