#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<m;i++) cin>>b[i];
    multiset<int> s;
    for (int i=0;i<n;i++) s.insert(a[i]);
    for (int i=0;i<m;i++){
        int temp = b[i];
        auto it = s.upper_bound(temp);
        if (it==s.begin()) cout<<-1<<endl;
        else{
            it--;
            cout<<*it<<endl;
            s.erase(it);
        }
    }
}