#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin>>n;
    ll target = ((ll)n*n+1)/2;
    ll low = 1, high = (ll)n*n;
    
    while (low < high) {
        ll mid = low+(high-low)/2;
        ll count = 0;
        for (int i=1;i<=n;i++) {
            count += min((ll)n, mid/i);
        }
        if (count>=target)
            high = mid;
        else
            low = mid+1;
    }
    cout<<low<<endl;
}
