//min25筛 cal sum[1,n]f(n) 非完全积性函数 f(p^k)=(p^k)*(p^k-1)
//blog:https://www.cnblogs.com/dysyn1314/p/13449083.html
//test:P5325 https://www.luogu.com.cn/record/128645161
#include <bits/stdc++.h>
using namespace std;using ll=long long;
const int N=1e5+5,L=1e4+5,M=1e9+7,inv6=166666668;
ll n,sqrtn,priarr[L],sump[L],sum2p[L],pt,g1[N<<1],g2[N<<1],val[N<<1];bool v[N];
void sieve(int n){for(int i=2;i<=n;i++){
	if(!v[i])priarr[++pt]=i,sump[pt]=(sump[pt-1]+i)%M,sum2p[pt]=(sum2p[pt-1]+(ll)i*i%M)%M;		
	for(int j=1;j<=pt&&priarr[j]*i<=n;j++){v[priarr[j]*i]=1;if(i%priarr[j]==0)break;}}}
int id1[N],id2[N];inline int get_id(ll x){return ((x<=sqrtn)?id1[x]:id2[n/x]);}
ll getS(ll x,ll y){
	if(x<priarr[y]||x<=1)return 0;int k=get_id(x);
	ll res=((g2[k]-g1[k]-sum2p[y-1]+sump[y-1])%M+M)%M;
	for(int i=y;i<=pt&&priarr[i]*priarr[i]<=x;i++){
		ll t1=priarr[i],t2=priarr[i]*priarr[i];
		for(int j=1;t2<=x;j++,t1=t2,t2*=priarr[i]){ll tt1=t1%M,tt2=t2%M;
			(res+=(getS(x/t1,i+1)*tt1%M*(tt1-1)%M)+(tt2*(tt2-1)%M))%=M;}}return res;}
void solve(){
	cin>>n;pt=0;sieve(sqrtn=sqrt(n));int tot=0;
	for(ll i=1,j;i<=n;i=j+1){
		j=n/(n/i);ll w=n/i;val[++tot]=w;(w<=sqrtn)?id1[w]=tot:id2[n/w]=tot;w%=M;
		g1[tot]=(w*(w+1)/2-1)%M;g2[tot]=((w*(w+1)%M*(2LL*w+1)%M*inv6%M)+M-1)%M;}
	for(int j=1;j<=pt;j++)for(int i=1;i<=tot&&priarr[j]*priarr[j]<=val[i];i++){
		int k=get_id(val[i]/priarr[j]);
		(g1[i]-=priarr[j]*(g1[k]-sump[j-1])%M-M)%=M;
		(g2[i]-=priarr[j]*priarr[j]%M*(g2[k]-sum2p[j-1])%M-M)%=M;}
	cout<<(getS(n,1)+1)%M<<'\n';}
int main(){ios::sync_with_stdio(0);solve();}
