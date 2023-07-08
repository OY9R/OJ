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
const int N=2e5+5;
int dp[N],id[N];
vector<PII> g[N];
void dfs(int u){
	for(auto v:g[u]){
		cout<<'!';
		if(dp[v.fi]==0){
			dp[v.fi]=dp[u]+(v.se<=id[u]);
			id[v.fi]=v.se;
			dfs(v.fi);
		}
	}
}
void solve(){
	int n;cin>>n;
    rep(i,1,n+1){
		dp[i]=id[i]=0;
		g[i].clear();
	}
	rep(i,1,n){
		int u,v;cin>>u>>v;
		g[u].pb(mp(v,i));
		g[v].pb(mp(u,i));
	}
	dp[1]=1;
	dfs(1);
	int ans=0;
	rep(i,1,n+1)ans=max(ans,dp[i]);
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}