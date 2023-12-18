//https://pintia.cn/problem-sets/1705510247604809728
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int N = 1e6+10;
int dpt, spt, scpt,sorpt,dc;
vector<vector<int> >es,sor;
vector<int> dfn,low,stk,vis,scc;
void ini(int n)
{
    dfn.resize(n*4+10,0); low.resize(n*4+10,0); stk.resize(n*4+10,0);dc=2*n-1;
    vis.resize(n*4+10,0); scc.resize(n*4+10,0); es.resize(n*4+10);sor.resize(n*4+10);
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++dpt; stk[++spt] = u; vis[u] = 1;
    for (auto v : es[u])
    {
        if (!dfn[v])tarjan(v), low[u] = min(low[u], low[v]);
        else if (vis[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] != low[u])return; scpt++;
    while (vis[u])scc[stk[spt]] = scpt, vis[stk[spt]] = 0, spt--;
}
void solve()
{
    int n;cin>>n;vector<int>vals(n+1);for(int i=1;i<=n;i++)cin>>vals[i]; 
    if (n < 3) {(n == 1)?cout<<"NO\n":cout <<"1\n1\n";return;}ini(n);
    es[2].push_back(3);es[2*n-2].push_back(2*n-1);
    for(int i=1;i<=n-2;i++)es[2*i].push_back(2*i+3),es[2*i+2].push_back(2*i+1);
    map<ll, int>mpv;for (int i = 1; i <n; i++)
    {
        ll v = 1ll * N * vals[i] + vals[i + 1];
        int nv = mpv[v];if (!nv)mpv[v] =nv= ++sorpt;sor[nv].push_back(i);
    }
    for (int p= 1; p<= sorpt;p++)
    {
        int siz = sor[p].size(); vector<int>tr(siz); 
        for(int i=0;i<siz;i++)tr[i]=++dc,es[tr[i]].push_back(2*sor[p][i]);
        for(int i=1;i<siz;i++)es[tr[i]].push_back(tr[i-1]),es[2*sor[p][i]+1].push_back(tr[i-1]);
        for(int i=0;i<siz;i++)tr[i]=++dc,es[tr[i]].push_back(2*sor[p][i]);
        for(int i=siz-2;i>=0;i--)es[tr[i]].push_back(tr[i+1]),es[2*sor[p][i]+1].push_back(tr[i+1]);
    }
    for (int i = 2; i <= 2 * n + 1; i++)if (!dfn[i])tarjan(i);
    for (int i = 1; i <= n; i++)if (scc[2 * i]==scc[2*i+1]){cout<<"NO\n";return;}
    vector<int>arr;for (int i=1;i<=n;i++)if(scc[2*i]>scc[2*i+1])arr.push_back(i);
    aacout<<arr.size()<<'\n';for(auto k:arr)cout<<k<<' ';cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;//cin>>t;
    while (t--)solve();
}