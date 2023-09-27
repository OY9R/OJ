#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,n0=0,ans=0x3f3f3f3f;cin>>n;
    string s;cin>>s;s="#"+s;
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+(s[i]=='A'),n0+=s[i]=='B';
    for(int l=0;l<=n0;l++)ans=min(ans,pre[l]+pre[n]-pre[n-n0+l]);
    cout<<ans<<endl;
}