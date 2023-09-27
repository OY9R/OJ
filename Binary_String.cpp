#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int n=s.size(),n0=0,ans=0x3f3f3f3f;
        s="#"+s;
        vector<int> pre(n+1);
        for(int i=1;i<=n;i++)pre[i]=pre[i-1]+(s[i]=='1'),n0+=s[i]=='0';
        for(int l=0;l<=n0;l++)ans=min(ans,pre[l]+pre[n]-pre[n-n0+l]);
        cout<<ans<<endl;
    }
}