#include<bits/stdc++.h>
using namespace std;

int main(){
    long long low = 1, high = 1000000000;
    string resp;
    for(int i=0;i<30 && low<high;i++){
        long long mid = low+(high-low)/2;
        cout<<"? "<<mid<<endl<<flush;
        cin>>resp;
        if(resp=="YES") low = mid+1;
        else high = mid;
    }
    cout<<"! "<<low<<endl<<flush;
}