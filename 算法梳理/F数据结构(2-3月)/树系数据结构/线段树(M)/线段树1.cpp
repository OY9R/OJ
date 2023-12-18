#include<bits/stdc++.h>//https://www.luogu.com.cn/problem/P3372
using namespace std;using ll=long long;
struct Seg_tr//区加/区和
{
	struct node
	{
		int siz=1;ll val=0,delt=0;	
	};
	int B;vector<node>tr;
	void ini(int _n)//[0,n]
	{
		for(B=1;B<=_n;B<<=1);tr.resize(B<<1,node());
		for(int i=B-1;i;i--)tr[i].siz=tr[i<<1].siz*2;
	}
	void pull(int p)
	{
		tr[p].val=tr[p<<1].val+tr[p<<1|1].val+tr[p].delt*tr[p].siz;
	}
	void d_upd(int p,int v)
	{
		tr[p].delt+=v;tr[p].val+=v*tr[p].siz;
	}
	void updp(int l,int r,int L,int R,int pos,int v)
	{
		if(r<L||l>R)return;if(l<=L&&r>=R){d_upd(pos,v);return;}int mid=(L+R)/2;
		updp(l,r,L,mid,pos<<1,v);updp(l,r,mid+1,R,pos<<1|1,v);pull(pos);
	}
	void upd(int l,int r,int v){updp(l,r,0,B-1,1,v);}
	ll quep(int l,int r,int L,int R,int pos,ll pre)
	{
		if(r<L||l>R)return 0;if(l<=L&&r>=R)return tr[pos].val+pre*tr[pos].siz;int mid=(L+R)/2;
		return quep(l,r,L,mid,pos<<1,pre+tr[pos].delt)+quep(l,r,mid+1,R,pos<<1|1,pre+tr[pos].delt);
	}
	ll que(int l,int r){return quep(l,r,0,B-1,1,0);}	
};
struct S
{
	int n,m;Seg_tr A;
	void ini()
	{
		cin>>n>>m;A.ini(n);for(int i=1,x;i<=n;i++)cin>>x,A.upd(i,i,x);		
	}
	void solve()
	{
		ini();for(int i=1,op,l,r,v;i<=m;i++)
		{
			cin>>op;if(op==1)cin>>l>>r>>v,A.upd(l,r,v);
			else cin>>l>>r,cout<<A.que(l,r)<<'\n';
		}
	}
};
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t=1;//cin>>t;
	while(t--){S SS;SS.solve();}
}