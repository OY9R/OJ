#include<bits/stdc++.h>
using namespace std;
int graph[510][510];
int dis[510];
int vis[510];
int path[510];
int cnt[510];
int w[510];
int sum[510];
int n,m;
int st,ed;
void solve(){
    cin>>n>>m>>st>>ed;
    for(int i=0;i<n;i++){
        cin>>w[i];
        sum[i]=w[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j]=INT_MAX;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b]=graph[b][a]=c;
    }
    for(int i=0;i<n;i++){
        dis[i]=INT_MAX;
        vis[i]=0;
    }
    dis[st]=0;
    cnt[st]=1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(make_pair(0,st));
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int v=0;v<n;v++){
            if(!vis[v]&&graph[u][v]!=INT_MAX){
                if(dis[v]>dis[u]+graph[u][v]){
                    dis[v]=dis[u]+graph[u][v];
                    sum[v]=sum[u]+w[v];
                    path[v]=u;
                    cnt[v]=cnt[u];
                    q.push(make_pair(dis[v],v));
                }else if(dis[v]==dis[u]+graph[u][v]){
                    cnt[v]+=cnt[u];
                    if(sum[v]<sum[u]+w[v]){
                        sum[v]=sum[u]+w[v];
                        path[v]=u;
                        q.push(make_pair(dis[v],v));
                    }
                }
            }
        }
    }
    stack<int> s;
    s.push(ed);
    int temp=ed;
    while(path[temp]!=st){
        s.push(path[temp]);
        temp=path[temp];
    }
    s.push(st);
    cout<<cnt[ed]<<' '<<sum[ed]<<endl;
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }
}
int main(){
    solve();
	return 0;
}