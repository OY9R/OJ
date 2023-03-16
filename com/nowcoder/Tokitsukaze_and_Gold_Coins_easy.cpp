#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c[N][4],m[N][4];
bool st[N][4];
int t,n,k,x,y,ans;
void dfs(int x,int y,int f){
    if(m[x][y]||st[x][y])return;
    c[x][y]+=st[x][y]=1;
    if(x+f<=n&&x+f>=1)dfs(x+f,y,f);
    if(y+f<=3&&y+f>=1)dfs(x,y+f,f);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    for(cin>>t;t--;cout<<ans<<'\n'){
        ans=0;cin>>n>>k;
        memset(c,0,sizeof c);
        memset(m,0,sizeof m);
        while(k--)cin>>x>>y,m[x][y]^=1;
        memset(st,0,sizeof st);
        dfs(1,1,1);
        memset(st,0,sizeof st);
        dfs(n,3,-1);
        c[1][1]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
                ans+=c[i][j]==2;
    }
}