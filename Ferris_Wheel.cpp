#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int low=0, high=n-1;
    int count = 0;
    while(low<=high){
        if ((a[low]+a[high])<=x){
            count++;
            low++;
            high--;
        }
        else{
            count++;
            high--;
        }
    }
    cout<<count<<endl;
}