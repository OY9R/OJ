#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;cin>>t;
    while(t--){
        ll x,y,n;cin>>x>>y>>n;
        ll m=1;
        while(~x&1){
            x>>=1;
            m<<=1;
        }
        if(m<n){
            while(~y&1){
                y>>=1;
                m<<=1;
            }
        }
        if(m>=n){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}