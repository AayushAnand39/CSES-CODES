#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        long long sum = 1;
        for (int i=2;(long long)i*i<=x;i++){
            if (x%i==0){
                int e = 0;
                do {
                    e++;
                    x/=i;
                } while(x%i==0);
                sum*=(e+1);
            }
        }
        if (x>1) sum*=2;
        cout<<sum<<endl;
    }
}