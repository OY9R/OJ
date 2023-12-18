#include<bits/stdc++.h>
using namespace std;using ll=long long;const int M=998244353,P=20,K=18,N=2e5+10;//20/18
struct Khe{pair<int,int>bs[P+1];
	void ins(pair<int,int>p,int lim=-M){if(lim!=-M)dec(lim);
		for(int i=P;i>=0;i--)if(p.first&(1<<i)){if(!bs[i].first){bs[i]=p;return;}
			if(p.second>bs[i].second)swap(bs[i],p);p.first^=bs[i].first;}}
	void dec(int lim){for(int i=P;i>=0;i--)if(bs[i].second&&bs[i].second<=lim)bs[i]={0,0};}
	bool chk(int x){for(int i=P;i>=0;i--)if(x&(1<<i))x^=bs[i].first;return bool(x);}
	Khe operator+(const Khe &B){Khe A=*this;for(auto&k:B.bs)A.ins(k);return A;}
	void operator+=(const Khe &A){for(auto&k:A.bs)ins(k);}};
struct S
{
	int n;vector<vector<int>>es,fa;vector<int>val,dep;
	vector<Khe>Lbs;
	void ini()
	{
		es.resize(n+1);dep.resize(n+1);dep[0]=0;val.resize(n+1);Lbs.resize(n+1);
		fa.resize(n+1,vector<int>(K+1,0));for(int i=1;i<=n;i++)cin>>val[i];
		for(int i=1,u,v;i<n;i++)cin>>u>>v,es[u].push_back(v),es[v].push_back(u);
	}
	int glca(int a,int b)
	{
		if(dep[a]<dep[b])swap(a,b);
		for(int i=K,d=dep[a]-dep[b];i>=0;i--)if(d&(1<<i))a=fa[a][i];if(a==b)return a;
		for(int i=K;i>=0;i--)if(fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];return fa[a][0];
	}
	void spr(int x)
	{
		int F=fa[x][0];dep[x]=dep[F]+1;
		for(int i=1,G=F;i<=K;i++)G=fa[x][i]=fa[G][i-1];	
		Lbs[x]=Lbs[F];Lbs[x].ins({val[x],dep[x]});
		for(auto k:es[x])if(k!=F)fa[k][0]=x,spr(k);
	}
	void solve()
	{
		cin>>n;ini();spr(1);
		int q;cin>>q;for(int i=1,a,b,w;i<=q;i++)
		{
			cin>>a>>b>>w;int L=glca(a,b);
			Khe A=Lbs[a];A.dec(dep[L]-1);Khe B=Lbs[b];B.dec(dep[L]-1);
			Khe C=A+B;C.chk(w)?cout<<"NO\n":cout<<"YES\n";
		}
	}
};
int main(){ios::sync_with_stdio(0);cin.tie(0);int t=1;while(t--){S SS;SS.solve();}}