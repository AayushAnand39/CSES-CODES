#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_map<int,int> mp;
    for (int i=0;i<s.length();i++) mp[s[i]-'A']++;
    int flag=0;
    for (auto x:mp){
        if (x.second%2!=0){
            flag++;
        }
    }
    if (flag>1){
        cout<<"NO SOLUTION"<<endl;
    }
    else{
        string t(s.length(),' ');
        int left=0, right=s.length()-1;
        for (int i=0;i<s.length();i++){
            if (mp[s[i]-'A']%2==1){
                t[s.length()/2]=s[i];
                mp[s[i]-'A']--;
            }
            while(mp[s[i]-'A']>0){
                t[left++] = t[right--] = s[i];
                mp[s[i]-'A']-=2;
            }
        }
        cout<<t<<endl;
    }
}