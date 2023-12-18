//https://www.luogu.com.cn/record/120014137
//����
#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 15;
int n, m, sum, tim, top, s;
int p[maxn], head[maxn], sd[maxn], dfn[maxn], low[maxn];//DFN(u)Ϊ�ڵ�u������������ʱ�Ĵ�����(ʱ���)��Low(u)Ϊu��u�������ܹ�׷�ݵ��������ջ�нڵ�Ĵ���� 
int stac[maxn], vis[maxn];//ջֻΪ�˱�ʾ��ʱ�Ƿ��и��ӹ�ϵ 
int h[maxn], in[maxn], val[maxn];
vector<int>es[maxn];
int u[maxn * 10], v[maxn * 10];
void tarjan(int x)
{
	low[x] = dfn[x] = ++tim;
	stac[++top] = x; vis[x] = 1;
	for (auto v:es[x])
	{		
		if (!dfn[v])tarjan(v),low[x] = min(low[x], low[v]);		
		else if (vis[v])low[x] = min(low[x], low[v]);
	}
	if (dfn[x] == low[x])
	{
		int y;
		while (y = stac[top--])
		{
			sd[y] = x;vis[y] = 0;
			if (x == y) break;p[x] += p[y];
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> p[i];
	for (int i = 1; i <= m; i++)cin >> u[i] >> v[i], es[u[i]].push_back(v[i]); ;
	for (int i = 1; i <= n; i++){ if (!dfn[i]) tarjan(i); es[i].clear(); }
	for (int i = 1; i <= m; i++){int x = sd[u[i]], y = sd[v[i]]; if (x != y)es[x].push_back(y),in[y]++;}
	queue <int> q;
	for (int i = 1; i <= n; i++)if (sd[i] == i && !in[i])q.push(i), val[i] = p[i];
	for(;!q.empty();q.pop())
	{
		int k = q.front();
		for (auto v : es[k])
		{
			val[v] = max(val[v], val[k] + p[v]);
			if (!--in[v]) q.push(v);
		}
	}
	int ans = 0; for (int i = 1; i <= n; i++)ans = max(ans, val[i]); cout<<ans<<'\n';
	
}