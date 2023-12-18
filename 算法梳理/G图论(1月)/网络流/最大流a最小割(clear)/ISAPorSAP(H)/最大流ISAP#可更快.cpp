//ISAP isap常规速度快于dinic,多测小数据/码量不及,稳定性未知
//blog1:https://www.cnblogs.com/owenyu/p/6852664.html
//blog2:https://www.cnblogs.com/zhsl/archive/2012/12/03/2800092.html
//test:https://www.luogu.com.cn/problem/P3376
#include<bits/stdc++.h>
using namespace std;using ll=long long;const int inff=1e9+7;
struct Edge{int u,v;ll cap;};
struct ISAP{
	int n,m,S,T,tot=0;vector<int>hd,d,cur,fa,num,nxt;vector<Edge>e;
	ISAP(int _n,int _m):n(_n),m(_m),hd(_n+5,-1),d(_n+5,0),cur(_n+5),fa(_n+5),num(_n+5,0),nxt(_m*2+5),e(_m*2+5){}
	void Add(int u,int v,int val){e[tot].u=u;e[tot].v=v;e[tot].cap=val;nxt[tot]=hd[u];hd[u]=tot++;}
	void Addedge(int a,int b,int val){Add(a,b,val);Add(b,a,0);}
	ll Solve(int _S,int _T){
		S=_S,T=_T;int x,mi;ll flow=0;num[0]=n;
		for(int i=1;i<=n;i++)cur[i]=hd[i];x=S;while(d[S]<n)
		{if(x==T){ll a=inff;while(x!=S)a=min(a,e[fa[x]].cap),x=e[fa[x]].u;x=T;
			flow+=a;while(x!=S)e[fa[x]].cap-=a,e[fa[x]^1].cap+=a,x=e[fa[x]].u;}
		bool ok=0;for(int i=cur[x];i!=-1;i=nxt[i])if(e[i].cap&&d[x]==d[e[i].v]+1)
			{ok=1;fa[e[i].v]=i;cur[x]=i;x=e[i].v;break;}if(ok)continue;
		mi=n-1;for(int i=hd[x];i!=-1;i=nxt[i])if(e[i].cap&&d[e[i].v]<mi)mi=d[e[i].v];
		if(!(--num[d[x]]))break;d[x]=mi+1,num[d[x]]++;cur[x]=hd[x];if(x!=S)x=e[fa[x]].u;}return flow;}};
signed main()
{
	int n,m,S,T;cin>>n>>m>>S>>T;ISAP ISF(n,m);
	for(int i=1,u,v,val;i<=m;i++)cin>>u>>v>>val,ISF.Addedge(u,v,val);cout<<ISF.Solve(S,T)<<'\n';
}