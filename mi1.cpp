#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    bool flag=0;
    long long l,r,w;cin>>l>>r>>w;
    if(w==1)return cout<<(l==1?1:-1)<<endl,0;
    for(long long i=1;i<=r;i*=w)
        if(i>=l&&i<=r)flag=1,cout<<i<<' ';
    if(!flag)cout<<-1;
}