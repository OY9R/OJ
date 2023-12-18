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
int n,k;
vector<VI> g;
inline int dij(int s){
    VI dis(n+1,INF);
    dis[s]=0;
    priority_queue<PII>q;
    q.push({0,s});
    while(q.size()){
        PII tmp=q.top();q.pop();
        int d=tmp.fi,u=tmp.se;
        if(d!=dis[u])continue;
        for(int i:g[u])
            if(dis[u]+1<dis[i]){
                dis[i]=dis[u]+1;
                if(dis[i]<=n-k+1)
                    q.push({dis[i],i});
            }
    }
    int mx=0;
    rep(i,0,n)mx=max(mx,dis[i]);
    return mx;
}
void solve(){
	int m;cin>>n>>m>>k;
    g.resize(n);
    rep(i,0,m){
        int a,b;cin>>a>>b;a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int ans=0;
    rep(i,0,n)ans=max(ans,dij(i));
    if(ans<=n-k){
        cout<<n<<endl;
        for(int i=1;i<=n;i++)cout<<i<<' ';
    }else cout<<0<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}