#include<bits/stdc++.h>
using namespace std;
int mm[110][110];
bool visited[110];
int dp[110];
int n,m;
queue<int> que;
void bfs() {
	int w=1;
	dp[1]=0;
	while(true) {
		visited[w]=true;
		for(int i=1; i<=n; i++)
			if(!visited[i]&&mm[w][i]!=-1)
				dp[i]=min(dp[i],dp[w]+mm[w][i]);
		int mmin=INT_MAX;
		w=0;
		for(int i=2; i<=n; i++)
			if(!visited[i]&&dp[i]<mmin) {
				mmin=dp[i];
				w=i;
			}
		if(!w)break;
	}
}
int main() {
	while(cin>>n>>m&&n) {
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				mm[i][j]=-1;
		for(int i=1; i<=n; i++) {
			dp[i]=INT_MAX;
			visited[i]=false;
		}
		for(int i=1; i<=m; i++) {
			int a,b,c;
			cin>>a>>b>>c;
			mm[a][b]=c;
			mm[b][a]=c;
		}
		bfs();
		cout<<dp[n]<<endl;
	}
}