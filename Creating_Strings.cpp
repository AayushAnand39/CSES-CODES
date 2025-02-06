#include<bits/stdc++.h>
using namespace std;

void permutation(string& ds, string& nums, set<string>& ans, vector<int>& freq){
    if (ds.length()==nums.length()){
        ans.insert(ds);
        return;
    }
    for (int i=0;i<nums.length();i++){
        if (!freq[i]){
            ds.push_back(nums[i]);
            freq[i]=1;
            permutation(ds,nums,ans,freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}

int main(){
    string s;
    cin>>s;
    set<string> st;
    string temp;
    vector<int> freq(s.length(),0);
    permutation(temp,s,st,freq);
    cout<<st.size()<<endl;
    for (auto x:st){
        cout<<x<<endl;
    }
}