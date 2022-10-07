#include<bits/stdc++.h>
using namespace std;
const int N=505;
int X[N],Y[N];
int G[N][N],dist[N];
bool st[N];
int roads[N],ri;
int n,k;
void prim(){
	memset(dist,0x3f,sizeof dist);
	for(int i=0;i<n;i++){
		int t=-1;
		for(int j=1;j<=n;j++)
			if(!st[j]&&(t==-1||dist[t]>dist[j]))t=j;
		if(i&&dist[t]==0x3f3f3f3f)return;
		if(i)roads[ri++]=dist[t];
		st[t]=true;
		for(int j=1;j<=n;j++)dist[j]=min(dist[j],G[t][j]);
	}
}
int main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>X[i]>>Y[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int dx=(X[i]-X[j]),dy=(Y[i]-Y[j]);
			G[i][j]=dx*dx+dy*dy;
		}
	}
	prim();
	sort(roads,roads+ri,greater<int>());
	if(k>0)k--;
	printf("%.2lf\n",sqrt(roads[k]));
	return 0;
}