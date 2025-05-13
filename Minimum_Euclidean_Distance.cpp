#include<bits/stdc++.h>
using namespace std;

long long dist(const pair<long long, long long>& a, const pair<long long, long long>& b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int main(){
    int n;
    cin>>n;
    vector<pair<long long, long long>> vec(n);
    for (int i=0;i<n;i++) cin>>vec[i].first>>vec[i].second;
    long long minVal = LLONG_MAX;
    sort(vec.begin(),vec.end());
    set<pair<long long, long long>> s;
    s.insert({vec[0].second,vec[0].first});
    long long j = 0;
    for (long long i=1;i<n;i++){
        long long d = ceil(sqrt(minVal));
        while(j<i && vec[j].first<vec[i].first-d){
            s.erase({vec[j].second,vec[j].first});
            j++;
        }
        auto lb = s.lower_bound({vec[i].second-d,0});
        auto ub = s.upper_bound({vec[i].second+d,0});
        for (auto it=lb;it!=ub;it++){
            minVal = min(minVal,dist({it->second,it->first},vec[i]));
        }
        s.insert({vec[i].second,vec[i].first});
    }
    cout<<minVal<<endl;
}