#include<bits/stdc++.h>
using namespace std;

void f(int n, int a, int b, int c, vector<pair<int,int>>& vec){
    if (n==0) return;
    f(n-1,a,c,b,vec);
    vec.push_back({a,b});
    f(n-1,c,b,a,vec);
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> vec;
    f(n,1,3,2,vec);
    cout<<vec.size()<<endl;
    for (int i=0;i<vec.size();i++){
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }
}