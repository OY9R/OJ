//万能类欧板子
//test:https://www.luogu.com.cn/problem/P5170
//blog:https://www.luogu.com.cn/problem/solution/P5170
#include <iostream>
using namespace std;
typedef long long ll;
const int P=998244353;
ll t,p,q,r,l;
struct Node 
{
	ll cntu=0,cntr=0,sumi=0,sums=0,sqrs=0,prod=0;
	// U met|R met|sum of x|sum of 
	Node operator+(Node b)
	{
		Node c;
		c.cntu=(cntu+b.cntu)%P,c.cntr=(cntr+b.cntr)%P;
		c.sumi=(sumi+b.sumi+cntr*b.cntr)%P;c.sums=(sums+b.sums+cntu*b.cntr)%P;
		c.sqrs=(sqrs+b.sqrs+((cntu*cntu)%P)*b.cntr+(2*cntu*b.sums)%P)%P;
		c.prod=((prod+b.prod+((cntu*cntr)%P)*b.cntr)%P+cntu*b.sumi+cntr*b.sums)%P;
		return c;
	}
};
Node qpow (Node a,ll k){Node res;for(;k;a=a+a,k>>=1)if(k&1)res=res+a;return res;}
Node solve (ll p,ll q,ll r,ll l,Node U,Node R)
{
	if (!l) {return Node();}if (p>=q) {return solve(p%q,q,r,l,U,qpow(U,p/q)+R);}
	ll cntU=(l*p+r)/q;if (!cntU) {return qpow(R,l);}ll Rlastc=l-(q*cntU-r-1)/p;
	return qpow(R,(q-r-1)/p)+U+solve(q,p,(q-r-1)%p,cntU-1,R,U)+qpow(R,Rlastc);
}
void solve()
{
	cin>>l>>p>>r>>q;Node bU={1,0,0,0,0,0},bR={0,1,1,0,0,0};
	Node ans=qpow(bU,r/q)+solve(p,q,r%q,l,bU,bR);
	cout<<(ans.sums+r/q)%P<<' '<<(ans.sqrs+((r/q)%P)*((r/q)%P))%P<<' '<<ans.prod<<'\n';//[0,p]
	//cout<<ans.sums<<' '<<ans.sqrs<<' '<<ans.prod<<'\n';//(0,p]
}
int main () 
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t=1;cin>>t;while(t--)solve();
}