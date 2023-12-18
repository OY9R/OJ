//ÀýÌâ:https://codeforces.com/contest/1903/problem/F
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
        for(int i=1;i<=n;i++)if(scc[2*i]==scc[2*i+1])return 0;return 1;}};
struct S{
    int n,m,B1,B2;x2_sat x2s;
    void qseg(int l,int r,int L,int R,int pos,int x){
        if(l>r||r<L||l>R)return;if(L>=l&&R<=r){x2s.repush(x,B1+pos);return;}
        int mid=(L+R)>>1;qseg(l,r,L,mid,pos<<1,x);qseg(l,r,mid+1,R,pos<<1|1,x);}
    bool trial(int val){x2s.R_ini();val--;for(int i=1;i<=n;i++)
        qseg(max(1,i-val),i-1,1,B2,1,i*2+1),qseg(i+1,min(n,i+val),1,B2,1,i*2+1);return x2s.Solve(n);}
    void solve()
    {
        cin>>n>>m;B1=n*2+2;for(B2=1;B2<n;B2<<=1);x2s.ini(B1+B2*2+5);
        for(int i=1,u,v;i<=m;i++)cin>>u>>v,Cor(x2s.es,u,1,v,1);      
        for(int i=B2*2-1;i>1;i--)x2s.es[B1+(i>>1)].push_back(B1+i); 
        for(int i=1;i<=n;i++)x2s.es[B1+B2-1+i].push_back(i*2);int l=1,r=n+1;
        while(r-l>1){int mid=(l+r)/2;trial(mid)?l=mid:r=mid;}cout<<l<<'\n';
    }
};
int main(){ios::sync_with_stdio(0);cin.tie(0);int t=1;cin>>t;/**/while(t--){S SS;SS.solve();}}