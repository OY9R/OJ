#include <bits/stdc++.h>//组合数学/多项式插值 ttf:https://codeforces.com/contest/1731/problem/F
using namespace std;using ll=long long;const int N=201,M=998244353;
struct C_pack{//precal needed
	ll poww(ll bs,ll x){ll res=1;for(bs=(bs%M+M)%M;x;x>>=1,(bs*=bs)%=M)if(x&1)(res*=bs)%=M;return res;}
	ll invv(ll bs){return poww(bs,M-2);}vector<ll>mul,inv;
	void precal(int P){mul.resize(P+1);mul[0]=1;for(int i=1;i<=P;i++)mul[i]=mul[i-1]*i%M;
		inv.resize(P+1);inv[P]=invv(mul[P]);for(int i=P;i;i--)inv[i-1]=inv[i]*i%M;}
	ll C(int n,int m){if(n<m)return 0;return mul[n]*inv[m]%M*inv[n-m]%M;}
	int interpolate(vector<int>&F,int n,int x)//get F[x];[1,n]:val(i)=F[i]
		{if(x<=n)return F[x];int ans=0;ll prod=1;for(int i=1;i<=n;i++)(prod*=(x-i))%=M;	
		for(int i=1;i<=n;i++)(ans+=prod*poww(x-i,M-2)%M*F[i]%M*inv[i-1]%M*inv[n-i]%M*(M+1-((n-i)&1)*2)%M)%=M;return ans;}
}xC;
void solve(){int n,k;cin>>n>>k;vector<int>vofp(n+4,0);
	for(int i=1;i<=n;i++)for(int x=0;x<i;x++)for(int y=x+1;y<=n-i;y++)for(int val=1;val<=n+3;val++)
		(vofp[val]+=(ll(xC.C(i-1,x))*xC.poww(val-1,x)%M)*xC.poww(k+1-val,i-1-x)%M
			*(ll(xC.C(n-i,y))*xC.poww(k-val,y)%M)%M*xC.poww(val,n-i-y)%M*val%M)%=M;
	for(int i=2;i<=n+3;i++)(vofp[i]+=vofp[i-1])%=M;cout<<xC.interpolate(vofp,n+3,k)<<"\n";}
void precal(){xC.precal(N);}
int main(){ios::sync_with_stdio(0);cin.tie(0);precal();int t=1;/*cin>>t;*/while(t--)solve();}