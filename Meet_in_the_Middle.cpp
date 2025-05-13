#include <bits/stdc++.h>
using namespace std;
 
void f(vector<long long>& a, int st, int en, long long curSum, vector<long long>& sums) {
    if (st==en) {
        sums.push_back(curSum);
        return;
    }
    f(a,st+1,en,curSum,sums);
    f(a,st+1,en,curSum+a[st],sums);
}
 
int main(){
    int n;
    long long x;
    cin>>n>>x;
    vector<long long> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    int mid = n/2;
    vector<long long> left, right;
    f(a, 0, mid, 0, left);
    f(a, mid, n, 0, right);
    sort(right.begin(), right.end());
    long long ways = 0;
    for (long long y:left) {
        long long target = x-y;
        auto range = equal_range(right.begin(),right.end(),target);
        ways+=(range.second-range.first);
    }
    cout<<ways<<endl;
}
