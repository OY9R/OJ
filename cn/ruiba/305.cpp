#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=123456789;

ll factorial(ll x){
    ll ret=1;
    for(ll i=2;i<=x;i++){
        ret*=i;
        ret%=mod;
    }
    return ret;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll ans=factorial(a)-factorial(b);
        if(ans)
            cout<<(ans>0?'a':'b')<<'\n';
        else
            cout<<"tie\n";
    }
    return 0;
}