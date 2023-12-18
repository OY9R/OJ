//¿ìËÙÃİ#ÄæÔª#½×³Ë#calcC
#include<bits/stdc++.h>
using namespace std;using ll=long long;const int M=998244353;
struct calcC{//precal needed
	ll poww(ll bs,ll x){ll res=1;for(bs=(bs%M+M)%M;x;x>>=1,(bs*=bs)%=M)if(x&1)(res*=bs)%=M;return res;}
	ll invv(ll bs){return poww(bs,M-2);}vector<ll>mul,inv;
	void precal(int P){mul.resize(P+1);mul[0]=1;for(int i=1;i<=P;i++)mul[i]=mul[i-1]*i%M;
		inv.resize(P+1);inv[P]=invv(mul[P]);for(int i=P;i;i--)inv[i-1]=inv[i]*i%M;}
	ll C(int n,int m){if(n<m)return 0;return mul[n]*inv[m]%M*inv[n-m]%M;}}xC;
int main(){ios::sync_with_stdio(0);cin.tie(0);xC.precal(2e5+10);}