#include <bits/stdc++.h>//¾ØÕóÇóÄæ test:https://www.luogu.com.cn/problem/P4783
using namespace std;using ll=long long;const double eps=1e-10;const int M=1e9+7;
struct calcC{//precal needed
	ll poww(ll bs,ll x){ll res=1;for(;x;x>>=1,(bs*=bs)%=M)if(x&1)(res*=bs)%=M;return res;}
	ll invv(ll bs){return poww(bs,M-2);}}xC;
struct Mat{
	int n,m;vector<vector<ll>>mat;Mat(int _n,int _m){ini(_n,_m);}
	void ini(int _n,int _m){n=_n,m=_m,mat.resize(n,vector<ll>(m,0));}
	int Gauss(){//0:none/1:only sol/2:multi sol
		int pt=0;for(int c=0;c<n;c++){
			int t=pt;for(int i=pt;i<n;i++)if(mat[i][c]>mat[t][c])t=i;
			if(!mat[t][c])continue;swap(mat[t],mat[pt]);for(int i=m-1,R=xC.invv(mat[pt][c]);i>=c;i--)(mat[pt][i]*=R)%=M;
			for(int i=0;i<n;i++)if(pt!=i&&mat[i][c])for(int j=m-1;j>=c;j--)(mat[i][j]+=(M-mat[pt][j]*mat[i][c]%M))%=M;pt++;}
		if(pt==n)return 1;for(int i=pt;i<n;i++)for(int j=n;j<m;j++)if(mat[i][j])return 0;return 2;}
	void outp(){for(int i=0;i<n;i++)for(int j=0;j<m;j++)cout<<mat[i][j]<<" \n"[j==m-1];cout<<"%%%\n";}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;Mat A(n,n*2);
	for(auto &k:A.mat)for(int i=0;i<n;i++)cin>>k[i];for(int i=0;i<n;i++)A.mat[i][n+i]=1;
	if(A.Gauss()!=1){cout<<"No Solution\n";return 0;}
	for(int i=0;i<n;i++)for(int j=n;j<n*2;j++)cout<<A.mat[i][j]<<" \n"[j==n*2-1];
}