#include<bits/stdc++.h>
using namespace std;

void decimalToBinary(int x, int n){
    vector<int> binary(x);
    int i=0;
    while(x>0){
        binary[i]=x%2;
        x/=2;
        i++;
    }
    for (int j=0;j<n-i;j++) cout<<'0';
    for (int j=i-1;j>=0;j--) cout<<binary[j];
}

int main(){
    int n;
    cin>>n;
    for (int i=0;i<(1<<n);i++){
        int x = i^(i>>1);
        decimalToBinary(x,n);
        cout<<endl;
    }
}

