#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    vector<int> temp;
    for (int i=0;i<n;i++){
        auto it = lower_bound(temp.begin(),temp.end(),a[i]);
        if (it==temp.end()) temp.push_back(a[i]);
        else *it = a[i];
    }
    cout<<temp.size()<<endl;
}