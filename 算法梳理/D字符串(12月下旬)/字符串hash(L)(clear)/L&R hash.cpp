#include<bits/stdc++.h>//L/R Hash ttf:https://codeforces.com/gym/103729/problem/J
using namespace std;using ll=long long;const int M=998244353;
struct Hsr{ll res[2];int len;};
struct Hash{
	string s;int n;vector<vector<ll>>l,r,b;int mod[2]={998244353,int(1e9+9)},fac[2]={9527,3860};
	Hsr GhL(int L,int R){Hsr C;C.len=R-L+1;for(int e=0;e<2;e++)C.res[e]=
		(l[e][R]-l[e][L-1]*b[e][R-L+1]%mod[e]+mod[e])%mod[e];return C;}
	Hsr GhR(int L,int R){Hsr C;C.len=R-L+1;for(int e=0;e<2;e++)C.res[e]=
		(r[e][L]-r[e][R+1]*b[e][R-L+1]%mod[e]+mod[e])%mod[e];return C;}
	Hsr Hplus(Hsr A,Hsr B){Hsr C;C.len=A.len+B.len;for(int e=0;e<2;e++)C.res[e]=
		(A.res[e]*b[e][B.len]%mod[e]+B.res[e])%mod[e];return C;}
	int tran(char c){if(c>='a')return c-'a'+27;if(c>='A')return c-'A'+11;return c-'0'+1;}
	void ini(string &_s){s=_s;n=s.length();b.resize(2,vector<ll>(n+2));
		l.resize(2,vector<ll>(n+2));r.resize(2,vector<ll>(n+2));
		for(int e=0;e<2;e++)b[e][0]=1,l[e][0]=0,r[e][n+1]=0;
		for(int e=0;e<2;e++)for(int i=1;i<=n;i++){b[e][i]=b[e][i-1]*fac[e]%mod[e];
			l[e][i]=(l[e][i-1]*fac[e]+tran(s[i-1]))%mod[e];
			r[e][n+1-i]=(r[e][n+2-i]*fac[e]+tran(s[n-i]))%mod[e];}}}Hs;
bool eq(Hsr&A,Hsr&B){return A.res[0]==B.res[0]&&A.res[1]==B.res[1]&&A.len==B.len;}