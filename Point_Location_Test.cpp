#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        if (((y3-y1)*(x2-x1)-(x3-x1)*(y2-y1))>0) cout<<"LEFT"<<endl;
        else if (((y3-y1)*(x2-x1)-(x3-x1)*(y2-y1))<0) cout<<"RIGHT"<<endl;
        else cout<<"TOUCH"<<endl;
    }
}