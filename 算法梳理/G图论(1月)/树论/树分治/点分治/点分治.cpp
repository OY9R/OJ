//点分治 test(60pt):https://www.luogu.com.cn/problem/P3806
#include<bits/stdc++.h>
using namespace std;const int N=1e4+10,N2=1e7+10;
int n,m,S,siz[N],mx[N],root,vis[N],ans[N2],dis[N],dpt,a[N];
struct edge { int to,cost;edge(int t=0,int co=0) { to=t;cost=co; } };
vector<edge>es[N];
void findroot(int x,int fa){
    siz[x]=1;mx[x]=0;
    for(auto v:es[x])if(!vis[v.to]&&v.to!=fa)
        findroot(v.to,x),siz[x]+=siz[v.to],mx[x]=max(mx[x],siz[v.to]);
    mx[x]=max(mx[x],S-siz[x]);if(mx[x]<mx[root])root=x;}
void get_dis(int x,int fa){dis[++dpt]=a[x];for(auto v:es[x])
    if(!vis[v.to]&&v.to!=fa)a[v.to]=a[x]+v.cost,get_dis(v.to,x);}
void calc(int s,int len,int w){
    dpt=0;a[s]=len;get_dis(s,0);
    for(int a=1;a<=dpt;a++)for(int b=a+1;b<=dpt;b++)
        if(dis[a]+dis[b]<N2-5)ans[dis[a]+dis[b]]+=w;}
void solve_subtree(int x){//A-B:以x为顶点实际答案
    calc(x,0,1);/*A*/vis[x]=1;
    for(auto v:es[x])if(!vis[v.to]){
        calc(v.to,v.cost,-1);/*B*/S=siz[x];root=0;
        findroot(v.to,x);solve_subtree(root);}}
int main(){ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;for(int i=1,x,y,z;i<n;i++)cin>>x>>y>>z,
        es[x].push_back(edge(y,z)),es[y].push_back(edge(x,z));
    S=n;mx[0]=n;root=0;findroot(1,0);solve_subtree(root);
    for(int i=1,k;i<=m;i++)cin>>k,cout<<((ans[k])?"AYE":"NAY")<<'\n';}