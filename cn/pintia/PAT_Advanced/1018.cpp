#include<bits/stdc++.h>
using namespace std;
const int inf=INT_MAX;
const int Nmax=600;
int Cmax,N,Sp,M,mmin=inf,mout=inf;
int C[Nmax],G[Nmax][Nmax],dist[Nmax];
bool visited[Nmax];
vector<int> pre[Nmax];
vector<int> path,tpath;
void dj(){
	fill(dist,dist+Nmax,inf);
	dist[0]=0;
	while(true){
		int u=-1,min=inf;
		for(int i=0;i<N;i++)
			if(!visited[i]&&dist[i]<min)
				min=dist[i],u=i;
		if(u==-1)return;
		visited[u]=1;
		for(int i=0;i<=N;i++)
			if(!visited[i]&&G[u][i]!=inf)
				if(dist[u]+G[u][i]<dist[i]){
					dist[i]=dist[u]+G[u][i];
					pre[i].clear();
					pre[i].push_back(u);
				}else if(dist[u]+G[u][i]==dist[i])
					pre[i].push_back(u);
	}
}
void dfs(int sp){
	tpath.push_back(sp);
	if(sp!=0){
		for(int i=0;i<pre[sp].size();i++)
			dfs(pre[sp][i]);
	}else{
		int mint=0,moutt=0;
		for(int i=tpath.size()-2;i>=0;i--)
			if(moutt+C[tpath[i]]<Cmax/2)
				mint+=Cmax/2-(moutt+C[tpath[i]]),moutt=0;
			else moutt+=C[tpath[i]]-Cmax/2;
		if(mint<mmin)
			mmin=mint,path=tpath,mout=moutt;
		else if(mint==mmin&&mout>moutt)
			path=tpath,mout=moutt;
	}
	tpath.pop_back();
}
int main(){
	fill(G[0],G[0]+Nmax*Nmax,inf);
	cin>>Cmax>>N>>Sp>>M;
	for(int i=1;i<=N;i++)cin>>C[i];
	for(int i=0;i<M;i++){
		int a,b,c;
		cin>>a>>b>>c;
		G[a][b]=c;
		G[b][a]=c;
	}
	dj();
	dfs(Sp);
	cout<<mmin<<' ';
	for(int i=path.size()-1;i>=0;i--)
		cout<<path[i]<<(i?"->":"");
	cout<<' '<<mout<<'\n';
	return 0;
}