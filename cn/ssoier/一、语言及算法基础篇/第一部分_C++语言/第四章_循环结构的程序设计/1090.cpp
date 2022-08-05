#include<bits/stdc++.h>
using namespace std;
long long n,m;
int k;
int main(){
    cin>>m>>k;
    if (m%19==0){
        int a=0;
        while(m){
            if(m%10==3) a++;
            m/=10;
        }
        if(a==k){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}