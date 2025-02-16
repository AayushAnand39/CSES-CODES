#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    queue<int> q;
    for (int i=1;i<=n;i++) q.push(i);
    int flag=0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if (flag==1){
            cout<<x<<" ";
        }
        else{
            q.push(x);
        }
        flag^=1;
    }
    cout<<endl;
}