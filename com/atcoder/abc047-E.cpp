// rewrite by: https://www.luogu.com.cn/blog/GetKeyState/solution-p1364
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=100100;
int w[N],s[N],ff[N],ans=INT_MAX;
int h[N],e[N],ne[N],idx=0;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u,int f,int d){
    s[u]=w[u];
    for(int i=h[u];~i;i=ne[i])
        if(e[i]!=f)
            dfs(e[i],u,d+1),
            s[u]+=s[e[i]];
    ff[1]+=w[u]*d;
}
void dp(int u,int f){
    for(int i=h[u];~i;i=ne[i])
        if(e[i]!=f)
            ff[e[i]]=ff[u]+s[1]-s[e[i]]*2,
            dp(e[i],u);
    ans=min(ans,ff[u]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(h,-1,sizeof h);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>w[i]>>a>>b;
        if(a)add(i,a),add(a,i);
        if(b)add(i,b),add(b,i);
    }
    dfs(1,0,0);dp(1,0);
    cout<<ans<<endl;
    return 0;
}