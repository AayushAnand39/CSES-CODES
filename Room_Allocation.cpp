#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> vec(n);
    for (int i=0;i<n;i++) cin>>vec[i].first>>vec[i].second;
    vector<vector<int>> temp(n,vector<int>(3));
    for (int i=0;i<n;i++){
        temp[i][0]=vec[i].first;
        temp[i][1]=vec[i].second;
        temp[i][2]=i;
    }
    sort(temp.begin(),temp.end());
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int count = 0;
    vector<int> res(n);
    for (int i=0;i<n;i++){
        if (pq.empty() || pq.top().first>=temp[i][0]){
            count++;
            pq.push({temp[i][1],count});
            res[temp[i][2]] = count;
        }
        else{
            int x = pq.top().second;
            pq.pop();
            pq.push({temp[i][1],x});
            res[temp[i][2]]=x;
        }
    }
    cout<<count<<endl;
    for (auto x:res) cout<<x<<" ";
    cout<<endl;
}