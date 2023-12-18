#include <bits/stdc++.h>//高斯消元 test:https://www.luogu.com.cn/problem/P3389
using namespace std;const double eps=1e-10;//ttf:https://qoj.ac/contest/1412/problem/7753
struct Mat{//0:none/1:only sol/2:multi sol
	int n,m;vector<vector<double>>mat;vector<int>sol;Mat(int _n,int _m){ini(_n,_m);}
	void ini(int _n,int _m){n=_n,m=_m,mat.resize(n,vector<double>(m,0));}
	int Gauss(){int pt=0;for(int c=0;c<n;c++){int t=pt;for(int i=pt;i<n;i++)if(abs(mat[i][c])>abs(mat[t][c]))t=i;
		if(abs(mat[t][c])<eps)continue;swap(mat[t],mat[pt]);for(int i=m-1;i>=c;i--)mat[pt][i]/=mat[pt][c];
		for(int i=0;i<n;i++)if(pt!=i&&abs(mat[i][c])>eps)for(int j=m-1;j>=c;j--)mat[i][j]-=mat[pt][j]*mat[i][c];pt++;}
		for(int i=pt+1;i<n;i++)if(abs(mat[i][m-1])>eps)return 0;return 2-bool(pt==n);}
	void outp(){for(int i=0;i<n;i++)for(int j=0;j<m;j++)cout<<mat[i][j]<<" \n"[j==m-1];cout<<"%%%\n";}};
int main(){ios::sync_with_stdio(0);cin.tie(0);int n;cin>>n;Mat A(n,n+1);for(auto &k:A.mat)for(auto &kk:k)cin>>kk;
	if(A.Gauss()!=1){cout<<"No Solution\n";return 0;}for(int i=0;i<n;i++)cout<<fixed<<setprecision(2)<<A.mat[i][n]<<'\n';}