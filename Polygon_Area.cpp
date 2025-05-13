#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<long long, long long>> vec(n);
    for (int i=0;i<n;i++) cin>>vec[i].first>>vec[i].second;
    long long area = 0;
    for (int i=0;i<n;i++){
        area+=((vec[i].first*vec[(i+1)%n].second)-(vec[(i+1)%n].first*vec[i].second));
    }
    cout<<abs(area)<<endl;
}