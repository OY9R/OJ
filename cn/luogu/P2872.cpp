#include<bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
int p[1001];
pair<double,double> e[1001];
vector<tuple<double,int,int> > g;
double range(int a,int b){
    return sqrt((e[a].X-e[b].X)*(e[a].X-e[b].X)+(e[a].Y-e[b].Y)*(e[a].Y-e[b].Y));
}
int find(int i){
    if(p[i]==i)return i;
    return p[i]=find(p[i]);
}
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        p[i]=i;
        cin>>e[i].X>>e[i].Y;
        for(int j=1;j<=i;j++)
            g.push_back({range(i,j),j,i});
    }
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        if(find(a)!=find(b))p[find(a)]=find(b);
    }
    sort(g.begin(),g.end());
    double ans=0;
    for(int i=0;i<g.size();i++){
        if(find(get<1>(g[i]))!=find(get<2>(g[i]))){
            p[find(get<1>(g[i]))]=find(get<2>(g[i]));
            //cout<<(get<0>(g[i]))<<' ';
            ans+=get<0>(g[i]);
        }
    }
    printf("%.2lf",ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // int n;cin>>n;
    // while(n--)
        solve();
    return 0;
}