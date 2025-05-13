#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* children[2];
    TrieNode(){
        children[0] = children[1] = nullptr;
    }
};

void insert(TrieNode* root, int num){
    TrieNode* node = root;
    for (int i=31;i>=0;i--){
        int bit = (num>>i)&1;
        if (!node->children[bit]){
            node->children[bit] = new TrieNode();
        }
        node = node->children[bit];
    }
}

int query(TrieNode* root, int num){
    TrieNode* node = root;
    int maxXor = 0;
    for (int i=31;i>=0;i--){
        int bit = (num>>i)&1;
        int desired = 1-bit;
        if (node->children[desired]){
            maxXor |= (1<<i);
            node = node->children[desired];
        }
        else node = node->children[bit];
    }
    return maxXor;
}

int maxSubarrayXor(vector<int>& a){
    TrieNode* root = new TrieNode();
    insert(root,0);
    int prefixXor = 0;
    int res = INT_MIN;
    for (int i=0;i<a.size();i++){
        prefixXor^=a[i];
        res = max(res,query(root,prefixXor));
        insert(root,prefixXor);
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    cout<<maxSubarrayXor(a)<<endl;
}