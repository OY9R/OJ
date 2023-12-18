//https://codeforces.com/contest/1874/my
//https://codeforces.com/contest/1874/submission/226535966
#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
vector<int>mul,inv,inv2;
ll poww(ll bs,ll x){ll ans=1;for(;x;x>>=1,(bs*=bs)%=M)if(x&1)(ans*=bs)%=M;return ans;}
ll invv(ll bs){return poww(bs,M-2);}
void precal(int P)//O(n^2logn)
{	
	mul.resize(P+5);mul[0]=1;for(int i=1;i<=P;i++)mul[i]=1ll*mul[i-1]*i%M;
	inv.resize(P+5);inv[P]=invv(mul[P]);for(int i=P;i;i--)inv[i-1]=1ll*inv[i]*i%M;
	inv2.resize(P+5);for(int i=1;i<=P;i++)inv2[i]=invv(i);
}
int C(int a,int b){return 1ll*mul[a]*inv[b]%M*inv[a-b]%M;}
void solve()
{	
	int n,m,len;cin>>n>>m;len=n*(n+1)/2;
	clock_t a=clock();
	if(m>len){cout<<"0\n";return;}len++;
	vector<ll>f(len+1),bef(len+1,0),res(len+1,0);bef[0]=1;
	for(int i=1;i<=len;i++)
	{
		vector<ll>val(n+1,0);val[0]=1;for(int j=len;j;j--)(bef[j]+=bef[j-1])%=M,(bef[j-1]*=(M-i))%=M;//O(n^4)
		for(int j=1,p=i;j<=n;(val[j]*=p)%=M,j++,p=1ll*p*i%M)for(int k=0;k<j;k++)//O(n^3)
			(val[j]+=1ll*val[k]*val[j-1-k]%M*C(j-1,k))%=M;f[i]=val[n];			
	}
	cout<<"TimeA:"<<double(clock()-a)<<'\n';a=clock();
	for(int i=1;i<=len;i++)//O(Large n^4)
	{
		for(int j=0;j<len;j++)(bef[j]*=(M-inv2[i]))%=M,(bef[j+1]+=(M-bef[j]))%=M;
		ll bs=1ll*inv[i-1]*inv[len-i]%M*f[i]%M;if((len-i)&1)bs=(M-bs)%M;		
		for(int j=0;j<=len;j++)(res[j]+=bs*bef[j]%M)%=M;		
		for(int j=len;j;j--)(bef[j]+=bef[j-1])%=M,(bef[j-1]*=(M-i))%=M;
	}
	cout<<"TimeB:"<<double(clock()-a)<<'\n';
	ll ans=0;for(int i=m;i<=len;i++)(ans+=res[i])%=M;cout<<ans<<'\n';	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);precal(21000);
	int t=1;//cin>>t;
	while(t--)solve();
}