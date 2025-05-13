#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    long long x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<long long> vec(n);
    vec[0] = x;
    for (int i=1;i<n;i++) vec[i] = (a*vec[i-1]+b)%c;
    long long sumXor = 0;
    long long sum = 0;
    for (int i=0;i<k;i++) sum+=vec[i];
    sumXor = sum;
    for (int i=k;i<n;i++){
        sum = sum+vec[i]-vec[i-k];
        sumXor^=sum;
    }
    cout<<sumXor<<endl;
}