#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    for(ll n,m;cin>>n>>m;){
        ll ans=0,cnt=0,cnt1=0;
        for(ll mm=m;mm;mm>>=1,cnt++)if(mm&1)cnt1++;
        if(cnt<n){cout<<"Impossible!\n";continue;}
        for(;cnt1<n;cnt1++)ans|=~m&-~m,m|=ans;
        for(;cnt1>n;cnt1--)ans|=m&-m,m-=m&-m;
        cout<<ans<<'\n';
    }
}