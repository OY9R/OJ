#include<bits/stdc++.h>
using namespace std;
int f[200010],g[200010];
map<pair<int,int>,int> m;
int F(int x){
    if(f[x]==x) return x;
    f[x]=F(f[x]);
    return f[x];
}
int G(int x){
    if(g[x]==x) return x;
    g[x]=G(g[x]);
    return g[x];
}
int main(){
    int n,k,l;cin>>n>>k>>l;
    for(int i=1;i<=n;i++){
        f[i]=i;g[i]=i;
    }
    for(int i=0;i<k;i++){
        int x,y;cin>>x>>y;
        f[F(x)]=F(y);
    }
    for(int i=0;i<l;i++){
        int x,y;cin>>x>>y;
        g[G(x)]=G(y);
    }
    for(int i=1;i<=n;i++)
        m[{F(i),G(i)}]++;
    for(int i=1;i<=n;i++)
        cout<<m[{F(i),G(i)}]<<' ';
    return 0;
}