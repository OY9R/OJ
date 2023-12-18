#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve(){
	int n,m,maxs=0;cin>>n>>m;
    vector<int> p(m),s(n),pi(m);
    for(int i=0;i<m;i++) cin>>p[i],pi[i]=i;
    sort(pi.begin(),pi.end(),[&](int a,int b){return p[a]>p[b];});
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        s[i]=i+1;
        for(int j=0;j<m;j++)
            s[i]+=(v[i][j]=='o')*p[j];
        maxs=max(maxs,s[i]);
    }
    for(int i=0;i<n;i++){
        int ans=0;
        for(int j=0;j<m&&s[i]<maxs;j++)
            s[i]+=(v[i][pi[j]]=='x')*p[pi[j]],ans+=(v[i][pi[j]]=='x');
        cout<<ans<<endl;
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}