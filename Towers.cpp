#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    vector<long long> vec;
    for (int i=0;i<n;i++){
        auto it = upper_bound(vec.begin(),vec.end(),a[i]);
        if (it==vec.end()) vec.push_back(a[i]);
        else *it = a[i];
    }
    cout<<vec.size()<<endl;
}