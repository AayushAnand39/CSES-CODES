#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> vec(n);
    for (int i=0;i<n;i++) cin>>vec[i].first>>vec[i].second;
    sort(vec.begin(),vec.end(),[](const pair<int,int>& a, const pair<int,int>& b){
        return a.second<b.second;
    });
    int x = 0, count = 0;
    for (int i=0;i<n;i++){
        if (vec[i].first>=x){
            count++;
            x=vec[i].second;
        }
    }
    cout<<count<<endl;
}