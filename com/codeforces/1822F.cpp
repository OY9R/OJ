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
const int INF=0x3f3f3f3f,mod=1e9+7,N=2e5+5;
VI ve[N];
ll n,k,c,dep[N],mxdep1[N],mxdep2[N];
int r1,r2;
void dfs(ll *p,int u,int fa,int &r){
    for(int v:ve[u]){
        if(v!=fa){
            p[v]=p[u]+1;
            dfs(p,v,u,r);
        }
    }
    if(p[u]>p[r])r=u;
}
void solve(){
    cin>>n>>k>>c;
    for(int i=1;i<=n;i++)ve[i].clear();
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    r1=r2=0;
    dep[1]=0;dfs(dep,1,0,r1);
    mxdep1[r1]=0;dfs(mxdep1,r1,0,r2);
    mxdep2[r2]=0;dfs(mxdep2,r2,0,r1);
    ll ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,max(mxdep1[i],mxdep2[i])*k-dep[i]*c);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    //cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}