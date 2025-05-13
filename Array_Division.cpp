#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long>& a, long long n, long long k, long long mid){
    long long p=1, sum=0;
    for (int i=0;i<n;i++){
        sum+=a[i];
        if (sum>mid){
            sum=a[i];
            p++;
        }
    }
    return p<=k;
}

int main(){
    long long n,k;
    cin>>n>>k;
    vector<long long> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    long long l = *max_element(a.begin(),a.end());
    long long h = accumulate(a.begin(),a.end(),0LL);
    long long res = 0;
    while(l<=h){
        long long mid = (l+h)/2;
        if (check(a,n,k,mid)){
            res = mid;
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<res<<endl;
}