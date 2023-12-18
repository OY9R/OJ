#include <bits/stdc++.h>//无向图三元环计数 test;https://www.luogu.com.cn/problem/P1989
using namespace std;using ll=long long;const double eps=1e-10;const int M=1e9+7;const ll inf=2e18;
struct S{
	int n,m,tc=0,res=0;vector<vector<int>>es;vector<int>tim,inc,u,v;
	void ini(){es.resize(n+1);tim.resize(n+1,0);inc.resize(n+1,0);u.resize(m+1);v.resize(m+1);}
	void solve(){cin>>n>>m;ini();for(int i=1;i<=m;i++)cin>>u[i]>>v[i],inc[u[i]]++,inc[v[i]]++;
		for(int i=1;i<=m;i++){bool j=(inc[u[i]]>inc[v[i]])||(inc[u[i]]==inc[v[i]]&&u[i]>v[i]);
			if(j)es[u[i]].push_back(v[i]);else es[v[i]].push_back(u[i]);}
		for(int i=1;i<=n;i++){for(auto k:es[i])tim[k]=i;for(auto k:es[i])
			for(auto kk:es[k])res+=(tim[kk]==i);}cout<<res<<'\n';}};
int main(){ios::sync_with_stdio(0);cin.tie(0);int t=1;/*cin>>t;*/while(t--){S SS;SS.solve();}}