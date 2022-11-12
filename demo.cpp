#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int primes[N],cnt;
int h[N],w[N],e[N],ne[N],idx;
bool st[N],vis[N];
void get_primes(int n){
    for(int i=2;i<=n;i++){
        if(!st[i])primes[cnt++]=i;
        for(int j=0;primes[j]<=n/i;j++){
            st[primes[j]*i]=true;
            if(i%primes[j]==0)break;
        }
    }
}
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int dfs(int u,int p) {
    vis[u]=true;
    int cnt=1;
    for(int i=h[u];i!=-1;i=ne[i]){
        if(w[e[i]]%p==0&&!vis[e[i]]){
            cnt+=dfs(e[i],p);
        }
    }
    return cnt;
}
int main() {
    get_primes(N-1);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    for(int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    int ans=0;
    for(int i=1;i<10;i++)
        for(int j=0;j<i;j++){
            memset(vis,0,sizeof(int)*n);
            for(int i=1;i<=n;i++)
                if(!vis[i])
                    ans=max(ans,dfs(i,primes[i]*primes[j]));
        }
    cout<<ans;
    return 0;
}