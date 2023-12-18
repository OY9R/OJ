//Ê÷ÆÊ test:https://www.luogu.com.cn/problem/P3379
#include <bits/stdc++.h>
using namespace std;using ll=long long;
struct HLD{//Ê÷ÆÊ&dfnÐò from jiangly https://codeforces.com/contest/1778/submission/191574156
    int n,cur=1;vector<vector<int>>es;vector<int>siz,dep,ga,fa,in,out,seq;
    HLD(int _n):n(_n+1),siz(n),ga(n),dep(n),fa(n,0),in(n),out(n),seq(n),es(n){}
    void addEdge(int u,int v){es[u].push_back(v),es[v].push_back(u);}
    void init(int root=1){ga[root]=root;dfs1(root);dfs2(root);}
    void dfs1(int u){if(fa[u])es[u].erase(find(es[u].begin(),es[u].end(),fa[u]));siz[u]=1;
        for(auto &v:es[u]){fa[v]=u;dep[v]=dep[u]+1;dfs1(v);siz[u]+=siz[v];if(siz[v]>siz[es[u][0]])swap(v,es[u][0]);}}
    void dfs2(int u){in[u]=cur++;seq[in[u]]=u;for(auto v:es[u])ga[v]=((v==es[u][0])?ga[u]:v),dfs2(v);out[u]=cur; }
    int lca(int u,int v){while(ga[u]!=ga[v])(dep[ga[u]]>dep[ga[v]])?u=fa[ga[u]]:v=fa[ga[v]];return dep[u]<dep[v]?u:v;}};
void solve(){int n,q,rt;cin>>n>>q>>rt;HLD tree(n);
    for(int i=1,u,v;i<n;i++)cin>>u>>v,tree.addEdge(u,v);tree.init(rt);
    for(int i=1,u,v;i<=q;i++)cin>>u>>v,cout<<tree.lca(u,v)<<'\n';}
int main(){ios::sync_with_stdio(0);cin.tie(0);int t=1;/*cin>>t;*/while(t--)solve();}
/*
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
const int N=5e5+10;int n,fa[N],ga[N],dep[N];vector<int>es[N];
int spr(int x,int lst){int siz=1,ma=0,sele=0; fa[x]=ga[x]=x;
    for(auto k:es[x])if(k!=lst){dep[k]=dep[x]+1;int sz=spr(k,x);
        siz+=sz;fa[k]=x;if(sz>ma)ma=sz,sele=k;}ga[sele]=x;return siz;}
void spr2(int x, int lst){ga[x]=ga[ga[x]];for(auto k:es[x])if(k!=lst)spr2(k,x);}
int getlca(int a,int b){while(ga[a]!=ga[b]){if(dep[ga[a]]<dep[ga[b]])
    swap(a,b);a=fa[ga[a]];}return(dep[a]<dep[b]?a:b);}
void solve(){int q,p;cin>>n>>q>>p;
    for(int i=1;i<n;i++){int u,v;cin>>u>>v;es[u].push_back(v),es[v].push_back(u);}
    spr(p,0);spr2(p,0);while(q--){int a,b;cin>>a>>b;cout<<getlca(a,b)<<"\n"; }}
int main(){ios::sync_with_stdio(0);cin.tie(0);solve();}
*/