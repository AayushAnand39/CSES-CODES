#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;
    for (long long i=1;i<=k;i++){
        long long x = (long long)(i*i*(i*i-1))/2;
        long long y = 4*(i-1)*(i-2);
        cout<<x-y<<endl;
    }
}