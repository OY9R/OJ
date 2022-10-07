#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int M[N+5][N+5],n,r;
int main(){
	cin>>n>>r;
	for(int i=0;i<n;i++){
		int x,y,v;
		cin>>x>>y>>v;
		M[x+1][y+1]=v;
	}
	for(int i=0;i<=N;i++)
		for(int j=1;j<=N;j++)
			M[i][j]+=M[i][j-1];
	for(int i=0;i<=N;i++)
		for(int j=1;j<=N;j++)
			M[j][i]+=M[j-1][i];
	int maxn=0;
	for(int i=0;i<=N-r;i++)
		for(int j=0;j<=N-r;j++)
			maxn=max(maxn,M[i][j]-M[i+r][j]-M[i][j+r]+M[i+r][j+r]);
	cout<<maxn<<endl;
	return 0;
}