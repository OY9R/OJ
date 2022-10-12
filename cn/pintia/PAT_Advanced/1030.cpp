#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, s, d;
int e[510][510], dis[510], cost[510][510];
vector<int> pre[510];
bool visit[510];
const int inf = 99999999;
vector<int> path, temppath;
int mincost = inf;
void dfs(int v,int tcost) {
	temppath.push_back(v);
	if(v == s) {
		if(tcost < mincost) {
			mincost = tcost;
			path = temppath;
		}
		temppath.pop_back();
		return ;
	}
	for(int i = 0; i < pre[v].size(); i++)
		dfs(pre[v][i],tcost+cost[v][pre[v][i]]);
	temppath.pop_back();
}
void dij() {
	pre[s].push_back(s);
	dis[s] = 0;
	for(int i = 0; i < n; i++) {
		int u = -1;
		for(int j = 0; j < n; j++) {
			if(visit[j] == false && (t==-1||dis[t]>dis[j]))
				u = j;
		}
		if(u == -1) break;
		visit[u] = true;
		for(int v = 0; v < n; v++) {
			if(visit[v] == false && e[u][v] != inf) {
				if(dis[v] > dis[u] + e[u][v]) {
					dis[v] = dis[u] + e[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if(dis[v] == dis[u] + e[u][v])
					pre[v].push_back(u);
			}
		}
	}
}
int main() {
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	scanf("%d%d%d%d", &n, &m, &s, &d);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		scanf("%d", &e[a][b]);
		e[b][a] = e[a][b];
		scanf("%d", &cost[a][b]);
		cost[b][a] = cost[a][b];
	}
	dij();
	dfs(d,0);
	for(int i = path.size() - 1; i >= 0; i--)
		printf("%d ", path[i]);
	printf("%d %d", dis[d], mincost);
	return 0;
}