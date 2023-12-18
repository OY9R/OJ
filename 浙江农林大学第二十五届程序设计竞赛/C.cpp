#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void dfs(int u,vector<VI>& g,VI& vis,int f){
    vis[u]=f;
    for (auto v:g[u])
        if(!vis[v])dfs(v,g,vis,f);
}
void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<bool> trap(n);
    rep(i,0,k){
        int x;cin>>x;
        trap[--x]=true;
    }
    vector<VI> g(n);
    rep(i,0,m){
        int a,b;cin>>a>>b;a--;b--;
        if(trap[a]&&trap[b])continue;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> vis(n);
    int f=1;
    rep(i,0,n)
        if(!vis[i])
            dfs(i,g,vis,f++);
    // rep(i,0,n)cout<<vis[i]<<' ';
    // cout<<endl;
    int q;cin>>q;
    while(q--){
        int s,e;cin>>s>>e;s--;e--;
        if(vis[s]==vis[e])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}