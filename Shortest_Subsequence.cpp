#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    int low = 0, high = 0;
    bool a=0, b=0, c=0, d=0;
    string temp;
    while(low<n){
        a=0, b=0, c=0, d=0;
        a+=(s[low]=='A');
        b+=(s[low]=='C');
        c+=(s[low]=='G');   
        d+=(s[low]=='T');
        high = low+1;
        while (high<n && (a+b+c+d)!=4){
            a+=(s[high]=='A');
            b+=(s[high]=='C');
            c+=(s[high]=='G');   
            d+=(s[high]=='T');
            high++;
        }
        if ((a+b+c+d)==4) temp+=s[high-1];
        low = high;
    }
    if ((a+b+c+d)==4) temp+='A';
    else if (!a) temp+='A';
    else if (!b) temp+='C';
    else if (!c) temp+='G';
    else if (!d) temp+='T';
    cout<<temp<<endl;
}