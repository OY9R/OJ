#include<bits/stdc++.h>
using namespace std;using ll=long long;const int M=998244353;
struct Persistent_Seg_tr//Ö÷Ï¯Ê÷
{//ttf:https://codeforces.com/gym/104566/problem/G
	struct node
	{
		int cnt=0,l=0,r=0;
	};
	int n,B,opt=0,dpt;vector<node>tr;vector<int>bgt;
	void ini(int _n)//[0,n]
	{
		n=_n;for(B=1;B<=n;B<<=1);tr.resize(B<<1,node());dpt=(B<<1)-1;
		for(int i=B-1;i;i--)tr[i].l=(i<<1),tr[i].r=(i<<1|1);bgt.resize(n+1);bgt[0]=1;
	}
	void updp(int L,int R,int pos,int v)
	{
		tr[pos].cnt++;if(L==R)return;int mid=(L+R)/2;
		if(v<=mid)tr.push_back(tr[tr[pos].l]),tr[pos].l=++dpt,updp(L,mid,dpt,v);
		else tr.push_back(tr[tr[pos].r]),tr[pos].r=++dpt,updp(mid+1,R,dpt,v);
	}
	void upd(int v)
	{
		tr.push_back(tr[bgt[opt]]);bgt[++opt]=++dpt;updp(0,B-1,dpt,v);
	}
	ll quep(int l,int r,int L,int R,int pos)
	{
		if(r<L||l>R)return 0;if(l<=L&&r>=R)return tr[pos].cnt;int mid=(L+R)/2;
		return quep(l,r,L,mid,tr[pos].l)+quep(l,r,mid+1,R,tr[pos].r);
	}
	ll que(int L,int R,int l,int r)
	{
		return quep(l,r,0,B-1,bgt[R])-quep(l,r,0,B-1,bgt[L-1]);
	}
};