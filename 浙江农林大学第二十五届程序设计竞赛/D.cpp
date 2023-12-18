#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
// #define mp make_pair
#define fi first
#define se second
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
vector<VI> g;
vector<int> vis;
vector<bool> trap;
vector<set<int>> ts;
void dfs(int u,int f){
    vis[u]=f;
    for(auto v:g[u]){
        if(trap[v])ts[v].insert(f);
        else if(!vis[v])dfs(v,f);
    }
}
bool mp[20000][20000];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    trap.resize(n);g.resize(n);vis.resize(n);ts.resize(n);
    rep(i,0,k){
        int x;cin>>x;
        trap[--x]=true;
    }
    rep(i,0,m){
        int a,b;cin>>a>>b;a--;b--;
        if(trap[a]&&trap[b])continue;
        g[a].pb(b),g[b].pb(a);
    }
    int f=1;
    rep(i,0,n)
        if(!vis[i]&&!trap[i])
            dfs(i,f++);
    // rep(i,0,n)cout<<vis[i]<<' ';cout<<endl;
    // cout<<f<<endl;
    while(f>20000);
    rep(i,0,n)
        if(trap[i]){
            vector<int> tmp;
            for(auto j:ts[i])tmp.pb(j);
            int nn=tmp.size();
            rep(j,0,nn-1)
                rep(k,j+1,nn)
                    mp[tmp[j]][tmp[k]]=true,
                    mp[tmp[k]][tmp[j]]=true;
        }
    int q;cin>>q;
    while(q--){
        int s,e;cin>>s>>e;s--;e--;
        // cout<<vis[s]<<vis[e]<<' ';
        if(vis[s]==vis[e])cout<<"YES"<<endl;
        else if(mp[vis[s]][vis[e]])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}