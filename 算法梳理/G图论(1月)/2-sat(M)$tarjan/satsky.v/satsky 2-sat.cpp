//2-sat test:https://www.luogu.com.cn/problem/P4782
//ÀýÌâ:https://atcoder.jp/contests/abc210/submissions/47081453
#include<bits/stdc++.h>
using namespace std;
void Cor(vector<vector<int>>&es,int u,int a,int v,int b)
    {es[u*2+(a^1)].push_back(2*v+b);es[v*2+(b^1)].push_back(2*u+a); }
struct x2_sat{//0/1:if select
    int dpt=0,spt=0,scpt=0,n;vector<vector<int>>es;
    vector<int>dfn,low,stk,vis,scc,re;x2_sat(int _n=0){ini(_n);}
    void ini(int _n=0){n=_n;es.resize(n);dfn.resize(n,0);
        low.resize(n);stk.resize(n);vis.resize(n,0);scc.resize(n);}
    /*¶à²â*/void R_ini(){while(!re.empty())es[re.back()].pop_back(),re.pop_back();
        dfn.assign(n,0);vis.assign(n,0);dpt=spt=scpt=0;}
    /*É¾±ß(re)*/void repush(int a,int b){re.push_back(a);es[a].push_back(b);}
    void tarjan(int u){dfn[u]=low[u]=++dpt;stk[++spt]=u;vis[u]=1;
        for(auto v:es[u]){if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
            else if(vis[v])low[u]=min(low[u],dfn[v]);}if(dfn[u]!=low[u])return;
        scpt++;while(vis[u])scc[stk[spt]]=scpt,vis[stk[spt]]=0,spt--;}
    bool Solve(int n){for(int i=2;i<=2*n+1;i++)if(!dfn[i])tarjan(i);
        for(int i=1;i<=n;i++)if(scc[2*i]==scc[2*i+1])return 0;return 1;} 
}x2s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);int n,m;cin>>n>>m;x2s.ini(n*2+2);
    for(int i=1,u,a,v,b;i<=m;i++)cin>>u>>a>>v>>b,Cor(x2s.es,u,a,v,b);
    bool jud=x2s.Solve(n);if(!jud){cout<<"IMPOSSIBLE\n";return 0;}
    cout<<"POSSIBLE\n";for(int i=1;i<=n;i++)cout<<bool(x2s.scc[2*i]>x2s.scc[2*i+1])<<" \n"[i==n];}