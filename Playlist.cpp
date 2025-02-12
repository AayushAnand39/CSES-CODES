#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    map<int,int> mp;
    int j=0, res=0;
    for (int i=0;i<n;i++){
        if (mp.find(a[i])==mp.end()){
            mp[a[i]] = i;
        }
        else{
            if (mp[a[i]]>=j){
                j = mp[a[i]]+1;
            }
            mp[a[i]]=i;
        }
        res = max(res,i-j+1);
    }
    cout<<res<<endl;
}