#include<bits/stdc++.h>
using namespace std;
int G[505][505],C[505][505];
int n,m,s,d;
int main(){
	cin>>n>>m>>s>>d;
	for(int i=0;i<m;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		G[a][b]=c;
		G[b][a]=c;
		C[a][b]=d;
		C[b][a]=d;
	}
	
	return 0;
}