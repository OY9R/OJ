//MCMF(��С���������) spfa+EK/֧�ָ�Ȩ��
//blog/source:https://www.luogu.com.cn/blog/user38055/solution-p3381
//test:https://www.luogu.com.cn/problem/P3381
//����:https://codeforces.com/gym/104725/problem/D
#include<bits/stdc++.h>
using namespace std;const int inf=2e9;
struct edg{int id,s,e,vol,cost;};
struct MCMF_spfa_EK{//satsky.ver//ans<2^31
    vector<edg>einfo;vector<vector<int>>es;
    int ans=0,maxf=0,tim=0,etot=-1;
    vector<int>dis,vis,inq,lst_e,mxf;//vis:update dis
    void add(int u,int v,int w,int f){
        einfo.push_back({++etot,u,v,w,f});es[u].push_back(etot);
        einfo.push_back({++etot,v,u,0,-f});es[v].push_back(etot);}
    bool spfa(int S,int T){
        queue<int>Q;Q.push(S);dis[S]=0;inq[S]=1,vis[S]=++tim;mxf[S]=inf;
        for(;!Q.empty();Q.pop()){int x=Q.front();inq[x]=0;vis[x]=tim;
            for(auto eid:es[x]){edg &k=einfo[eid];int des=k.e;
                if(vis[des]!=tim)dis[des]=inf;
                if(!k.vol||k.cost+dis[x]>=dis[des])continue;
                vis[des]=tim;dis[des]=dis[x]+k.cost;
                mxf[des]=min(mxf[x],k.vol);lst_e[des]=eid;
                if(!inq[des])inq[des]=1,Q.push(des);}}
        if(vis[T]!=tim)dis[T]=inf;return dis[T]!=inf;}
    void Solve(int S,int T){while(spfa(S,T)){for(int x=T,k;x!=S;x=einfo[k].s)//��С���������//���:��Ȩȫ��
  //void Solve(int S,int T){while(spfa(S,T)&&dis[T]<0){for(int x=T,k;x!=S;x=einfo[k].s)//��С���ÿ�����
        k=lst_e[x],einfo[k].vol-=mxf[T],einfo[k^1].vol+=mxf[T];
            maxf+=mxf[T];ans+=dis[T]*mxf[T];}} 
    void ini(int n){n++;dis.resize(n);inq.resize(n,0);vis.resize(n,0);
        lst_e.resize(n);mxf.resize(n);es.resize(n);}}Mcmf;
int main(){
    int n,m,S,T;cin>>n>>m>>S>>T;Mcmf.ini(n);
    for(int i=1,u,v,w,f;i<=m;i++)cin>>u>>v>>w>>f,Mcmf.add(u,v,w,f);
    Mcmf.Solve(S,T);cout<<Mcmf.maxf<<" "<<Mcmf.ans<<endl;}