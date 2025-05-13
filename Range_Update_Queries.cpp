#include<bits/stdc++.h>
using namespace std;

vector<long long> segtree(4*1000000,0);
vector<long long> lazy(4*1000000,0);
void build(long long node, long long start, long long end, vector<long long>& a){
    if (start==end){
        segtree[node] = a[start];
    }
    else{
        long long mid = (start+end)/2;
        build(2*node+1,start,mid,a);
        build(2*node+2,mid+1,end,a);
        segtree[node] = segtree[2*node+1] + segtree[2*node+2];
    }
}
void update(long long node, long long start, long long end, long long l, long long r, long long val){
    if (lazy[node] != 0){
        segtree[node] += (end-start+1)*lazy[node];
        if (start != end){
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start > end || start > r || end < l) return;
    if (start >= l && end <= r){
        segtree[node] += (end-start+1)*val;
        if (start != end){
            lazy[2*node+1] += val;
            lazy[2*node+2] += val;
        }
        return;
    }
    long long mid = (start+end)/2;
    update(2*node+1,start,mid,l,r,val);
    update(2*node+2,mid+1,end,l,r,val);
    segtree[node] = segtree[2*node+1] + segtree[2*node+2];
}

long long query(long long node, long long start, long long end, long long l, long long r){
    if (start > end || start > r || end < l) return 0;
    if (lazy[node] != 0){
        segtree[node] += (end-start+1)*lazy[node];
        if (start != end){
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start >= l && end <= r) return segtree[node];
    long long mid = (start+end)/2;
    long long p1 = query(2*node+1,start,mid,l,r);
    long long p2 = query(2*node+2,mid+1,end,l,r);
    return p1 + p2;
}

int main(){
    long long n,q;
    cin>>n>>q;
    vector<long long> a(n);
    for (long long i=0;i<n;i++) cin>>a[i];
    build(0,0,n-1,a);
    for (long long i=0;i<q;i++){
        long long t;
        cin>>t;
        if (t==1){
            long long l,r,x;
            cin>>l>>r>>x;
            l--;
            r--;
            update(0,0,n-1,l,r,x);
        }
        else if(t==2){
            long long x;
            cin>>x;
            cout<<query(0,0,n-1,x-1,x-1)<<endl;
        }
    }
}