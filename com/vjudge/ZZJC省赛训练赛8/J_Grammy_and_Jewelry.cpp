#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3007;

ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int> G[N];
int a[N],dis[N],vis[N],dp[N];
int n,m,T;
void dijkstra(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	for(int i=1;i<=n;i++)dis[i]=0x3f3f3f3f;
	q.push({0,1});
	dis[1]=0;
	while(!q.empty()){
		auto t=q.top();q.pop();
		vis[t.second]=1;
		for(auto v:G[t.second]){
			if(!vis[v]&&dis[v]>t.first+1){
				dis[v]=t.first+1;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	n=read();m=read();T=read();
	for(int i=2;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		if(u==v)continue;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dijkstra();
	for(int i=1;i<=n;i++){
		for(int j=dis[i]*2;j<=T;j++){
			dp[j]=max(dp[j],dp[j-dis[i]*2]+a[i]);
		}
	}
	for(int i=1;i<=T;i++)cout<<dp[i]<<" \n"[i==T];
}