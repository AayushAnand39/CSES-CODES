#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    vector<int> lps(t.length(),0);
    int i=1,j=0;
    while(i<t.length()){
        if (t[i]==t[j]){
            j++;
            lps[i]=j;
            i++;
        }
        else{
            if (j!=0) j=lps[j-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    i=0,j=0;
    int count = 0;
    while(i<s.length()){
        if (t[j]==s[i]){
            i++;
            j++;
        }
        if (j==t.length()){
            count++;
            j=lps[j-1];
        }
        else{
            if (i<s.length() && t[j]!=s[i]){
                if (j!=0) j=lps[j-1];
                else i++;
            }
        }
    }
    cout<<count<<endl;
}