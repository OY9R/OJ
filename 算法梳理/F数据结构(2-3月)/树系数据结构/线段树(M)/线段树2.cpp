#include<bits/stdc++.h>
using namespace std;using ll=long long;
ll mod;
struct Seg_tr//区加/区乘/区和
{
	struct node
	{
		int siz=1;ll val=0,k=1,b=0;//val未被k/b操作
		ll v2(){return (val*k+b*siz)%mod;}
	};
	int B;vector<node>tr;
	void ini(int _n)//[0,n]
	{
		for(B=1;B<=_n;B<<=1);tr.resize(B<<1,node());
		for(int i=B-1;i;i--)tr[i].siz=(tr[i<<1].siz*2)%mod;
	}
	void merge(ll&k,ll&b,ll k2,ll b2)
	{
		k=k*k2%mod,b=(b*k2+b2)%mod;
	}
	void pull(int p)
	{
		tr[p].val=(tr[p<<1].v2()+tr[p<<1|1].v2())%mod;
	}
	void d_upd(int p,ll k,ll b)
	{
		merge(tr[p].k,tr[p].b,k,b);
	}
	void push(int p)
	{
		for(int e=0;e<2;e++)d_upd((p<<1|e),tr[p].k,tr[p].b);
		tr[p].k=1;tr[p].b=0;
	}	
	void updp(int l,int r,int L,int R,int pos,ll k,ll b)
	{
		if(r<L||l>R)return;if(l<=L&&r>=R){d_upd(pos,k,b);return;}push(pos);int mid=(L+R)/2;
		updp(l,r,L,mid,pos<<1,k,b);updp(l,r,mid+1,R,pos<<1|1,k,b);pull(pos);
	}
	void upd(int l,int r,ll k,ll b){updp(l,r,0,B-1,1,k,b);}
	ll quep(int l,int r,int L,int R,int pos)
	{
		if(r<L||l>R)return 0;if(l<=L&&r>=R)return tr[pos].v2();push(pos);int mid=(L+R)/2;
		return pull(pos),(quep(l,r,L,mid,pos<<1)+quep(l,r,mid+1,R,pos<<1|1))%mod;
	}
	ll query(int l,int r){return quep(l,r,0,B-1,1);}
};
struct S
{
	int n,m;Seg_tr A;ll v;
	void ini()
	{
		cin>>n>>m>>mod;A.ini(n);for(int i=1;i<=n;i++)cin>>v,A.upd(i,i,1,v%mod);
	}
	void solve()
	{
		ini();for(int i=1;i<=m;i++)
		{
			int op,l,r;cin>>op;
			if(op==1)cin>>l>>r>>v,A.upd(l,r,v%mod,0);
			else if(op==2)cin>>l>>r>>v,A.upd(l,r,1,v%mod);			 
			else cin>>l>>r,cout<<A.query(l,r)<<'\n';
			//cout<<A.query(l,r)<<"***\n";
		}
	}
};
signed main()
{
	//freopen("1.in","r",stdin);
	ios::sync_with_stdio(0);cin.tie(0);
	int t=1;//cin>>t;
	while(t--){S SS;SS.solve();}
}