#include<iostream>
#include<cstring>
#include<queue>
#define endl '\n'
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f,N=310;
int n,np,nc,m;
int st[N],pre[N],g[N][N];
bool route(int s,int e){
    memset(st,0,sizeof st);
    memset(pre,-1,sizeof pre);
    queue<int> q;
    for(st[s]=1,q.push(s);q.size();q.pop()){
        int t=q.front();
        for(int i=0;i<n+2;i++)
            if(g[t][i]&&!st[i]){
                st[i]=1;
                pre[i]=t;
                if(i==e)return true;
                q.push(i);
            }
    }
    return false;
}
int maxflow(int s,int e){
    int res=0;
    while(route(s,e)){
        int minflow=INF;
        for(int t=e;pre[t]!=-1;t=pre[t])
            minflow=min(minflow,g[pre[t]][t]);
        res+=minflow;
        for(int t=e;pre[t]!=-1;t=pre[t]){
            g[pre[t]][t]-=minflow;
            g[t][pre[t]]+=minflow;
        }
    }
    return res;
}
void solve(){
    while(cin>>n>>np>>nc>>m){
        memset(g,0,sizeof g);
        char c;
        for(int i=0;i<m;i++){
            int f,t,v;cin>>c>>f>>c>>t>>c>>v;
            if(f!=t)g[f][t]=v;
        }
        for(int i=0;i<np;i++){
            int f,v;cin>>c>>f>>c>>v;
            g[n][f]=v;
        }
        for(int i=0;i<nc;i++){
            int f,v;cin>>c>>f>>c>>v;
            g[f][n+1]=v;
        }
        cout<<maxflow(n,n+1)<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}