#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
int n;
long long a[301],value[301];
bool g[301][301],st[301];
int dist[301];
pair<int,ll> dp[301][301];
void dij(int start){
    memset(dist,0x3f,sizeof dist);
    memset(st,false,sizeof st);
    dist[start]=0;
    value[start]=a[start];
    priority_queue<PII,vector<PII>,greater<PII> >heap;
    heap.push({0,start});
    while(heap.size()){
        auto t=heap.top();
        heap.pop();
        int v=t.se,d=t.fi;
        if(st[v])continue;
        st[v]=true;
        for(int i=0;i<n;i++){
            if(!g[v][i]||i==v)continue;
            if(dist[i]>d+g[v][i]){
                dist[i]=d+g[v][i];
                heap.push({dist[i],i});
                value[i]=value[v]+a[i];
            }
            if(dist[i]==d+g[v][i]){
                value[i]=max(value[i],value[v]+a[i]);
            }
        }
    }
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<n;j++)
            g[i][j]=s[j]=='Y';
    }
    int q;cin>>q;
    while(q--){
        int u,v;cin>>u>>v;u--,v--;
        int ans;
        if(!dp[u][v].fi){
            dij(u);
            dp[u][v]={dist[v],value[v]};
            for(int i=0;i<n;i++){
                dp[u][i]={dist[i],value[i]};
                //cout<<u<<"->"<<i<<'='<<dist[i]<<':'<<value[i]<<endl;
            }
        }
        if(dp[u][v].fi==INF){cout<<"Impossible\n";continue;}
        cout<<dp[u][v].fi<<' '<<dp[u][v].se<<endl;
    }
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    solve();
    return 0;
}