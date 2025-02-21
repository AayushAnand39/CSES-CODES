#include<bits/stdc++.h>
using namespace std;

bool check(long long mid, long long n, long long t, vector<long long>& a){
    long long sum=0;
    for (int i=0;i<n;i++){
        sum+=(mid/a[i]);
        if (sum>=t) return true;
    }
    return false;
}

int main(){
    long long n,t;
    cin>>n>>t;
    vector<long long> a(n);
    for (long long i=0;i<n;i++) cin>>a[i];
    long long low=1, high=(*min_element(a.begin(),a.end()))*t;
    long long res = 0;
    while(low<=high){
        long long mid = (low+high)/2;
        if (check(mid,n,t,a)){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<res<<endl;
}