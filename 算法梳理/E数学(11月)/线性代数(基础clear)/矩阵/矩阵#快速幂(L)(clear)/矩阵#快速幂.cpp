#include<bits/stdc++.h>//æÿ’Û#øÏÀŸ√›//test:https://www.luogu.com.cn/problem/P3390
using namespace std;typedef long long ll;int mod;
struct Mat
{
	int n;vector<vector<ll>>mat;Mat(int _n=0,bool b=1){ini(_n,b);}//m pre!!
	void ini(int _n=0,bool b=1){n=_n;mat.resize(n,vector<ll>(n,0));for(int i=0;i<n;i++)mat[i][i]=b;}	
	void inp(){for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>mat[i][j],mat[i][j]%=mod;}
	void outp(){for(int i=0;i<n;i++)for(int j=0;j<n;j++)cout<<mat[i][j]<<" \n"[j==n-1];}	
	Mat operator+(Mat &e){Mat res(n,0);for(int i=0;i<n;i++)for(int j=0;j<n;j++)
		res.mat[i][j]=(mat[i][j]+e.mat[i][j])%mod;return res;}
	Mat operator-(Mat &e){Mat res(n,0);for(int i=0;i<n;i++)for(int j=0;j<n;j++)
		res.mat[i][j]=(mat[i][j]-e.mat[i][j]+mod)%mod;return res;}
	Mat operator*(Mat &e){Mat res(n,0);for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)
		(res.mat[i][j]+=(mat[i][k]*e.mat[k][j]%mod))%=mod;return res;}
	Mat operator^(ll x){Mat res(n,1),A=*this;for(;x;x>>=1,A=A*A)if(x&1)res=res*A;return res;}	
	Mat CalMat1(int k){Mat A=*this;int n=A.n;Mat I(n,1);//Cal:A+A^2+...+A^k(%m) b[0]=pre[0]=I//test:http://poj.org/problem?id=3233
		vector<Mat>b(32);b[0]=I;b[1]=A;for(int i=2;i<=31;i++)b[i]=b[i-1]*b[i-1];//b[i]=A^(2^(i-1))
		vector<Mat>pre(31);pre[0]=I;for(int i=1;i<=30;i++){Mat Mx=pre[i-1]*b[i];pre[i]=pre[i-1]+Mx;}//pre[i]=sum[0,(2^(i-1)-1))A^j
		Mat res(n,0),B=I;k++;for(int i=30;i>=0;i--)if(k&(1<<i)){Mat Mx=pre[i]*B;res=res+Mx,B=B*b[i+1];}res=res-b[0];return res;}
};
//struct S{void solve(){ll n,k;cin>>n>>k;mod=1e9+7;Mat A(n,0);A.inp();Mat res=A^k;res.outp();}};
struct S{void solve(){int n,k,_m;cin>>n>>k>>_m;mod=_m;Mat A(n,0);A.inp();Mat res=A.CalMat1(k);res.outp();}};
int main(){ios::sync_with_stdio(0);cin.tie(0);int t=1;/*cin>>t;*/while(t--){S SS;SS.solve();}}