#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<pair<long long,long long>> vec(n);
    for (long long i=0;i<n;i++){
        cin>>vec[i].first>>vec[i].second;
    }
    vector<long long> temp1(n), temp2(n);
    for (long long i=0;i<n;i++){
        temp1[i] = vec[i].first;
        temp2[i] = vec[i].second;
    }
    sort(temp1.begin(),temp1.end());
    sort(temp2.begin(),temp2.end());
    long long i=0,j=0;
    long long x=0,y=0;
    while(i<n && j<n){
        if (temp1[i]<temp2[j]){
            x++;
            y = max(y,x);
            i++;
        }
        else{
            j++;
            x--;
        }
    }
    cout<<y<<endl;
}