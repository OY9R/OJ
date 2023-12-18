//¸ß½×ÀàÅ·°å×Ó from:https://loj.ac/s/1845933 
//test1:https://loj.ac/p/138 result:https://loj.ac/s/1907571
//test2:https://www.luogu.com.cn/problem/P5170 result:https://www.luogu.com.cn/record/128385587
#include <bits/stdc++.h>
using namespace std;using ll=long long;
const int K=10,mod=1e9+7;
struct hyper_likegcd{//cal sum[0,n](x^k1)*(((a*x+b)/c)^k2)
    int invs[K+2],binom[K+2][K+2],B[K+1],polys[K+1][K+2];
    int power_sum(int e,int x){ll ret=0;for(int i=0;i<e+2;i++)ret=(ret*x+polys[e][i])%mod;return ret*invs[e+1]%mod;}
    void init(){
        invs[0]=invs[1]=1;for(int i=2;i<=K+1;i++)invs[i]=1ll*invs[mod%i]*(mod-mod/i)%mod;
        for(int i=0;i<=K+1;i++){binom[i][0]=1;for(int j=1;j<=i;j++)binom[i][j]=(binom[i-1][j-1]+binom[i-1][j])%mod;}
        B[0]=1;for(int i=1;i<=K;i++){int s=0;for(int j=0;j<i;j++)(s+=1ll*binom[i+1][j]*B[j]%mod)%=mod;B[i]=1ll*s*(mod-invs[i+1])%mod;}
        for(int i=0;i<=K;i++){polys[i][i+1]=0;for(int j=0,sw=1;j<=i;j++,sw=(mod-sw)%mod)polys[i][j]=1ll*binom[i+1][j]*B[j]%mod*sw%mod;}polys[0][1]=1;}
    int scary_sum(int n,int a,int b,int c,int e1,int e2){
        using T=tuple<int,int,int,int>;stack<T> stac;const int S=e1+e2;
        vector<vector<int> >curr(K+1,vector<int>(K+1,0)),next(K+1,vector<int>(K+1,0));
        while(n>=0){stac.emplace(n,a,b,c);if(!a)break;if(a>=c)a%=c;else if(b>=c)b%=c;else n=(1ll*a*n+b)/c-1,b=c-1-b,swap(a,c);}    
        for(;!stac.empty();swap(curr,next)){tie(n,a,b,c)=stac.top();stac.pop();
            if(a==0){for(int e1=0,q=b/c;e1<=S;e1++)for(int e2=0,s=power_sum(e1,n);e2<=S-e1;e2++)next[e1][e2]=s,s=1ll*s*q%mod;}
            else if(a>=c||b>=c){int q=(a>=c)?a/c:b/c,d=(a>=c)?1:0;for(int e1=0;e1<=S;e1++)for(int e2=0;e2<=S-e1;e2++)
                {ll s=0;for(int i2=0,p=1;i2<=e2;i2++,p=1ll*p*q%mod)s+=1ll*p*binom[e2][i2]%mod*curr[e1+i2*d][e2-i2]%mod;next[e1][e2]=s%mod;}}
            else{int cumu[K+1][K+1],M=(1ll*a*n+b)/c;for(int e2=0;e2<=S-1;e2++)for(int e1=0;e1<=S-e2-1;e1++)
                {ll s=0;for(int j=0;j<=e1+1;j++)s+=1ll*(polys[e1][e1+1-j])*curr[e2][j]%mod;cumu[e1][e2]=1ll*(s%mod)*invs[e1+1]%mod;}                     
                for(int e1=0;e1<=S;e1++)for(int e2=0,p=power_sum(e1,n);e2<=S-e1;e2++)
                {ll t=0;for(int i2=0;i2<e2;i2++)t+=1ll*(cumu[e1][i2])*binom[e2][i2]%mod;next[e1][e2]=(p-t%mod+mod)%mod;p=1ll*p*M%mod;}}}
        return curr[e1][e2];}
}S;
void solve(){int N,a,b,c,e1,e2;cin>>N>>a>>b>>c>>e1>>e2;cout<<S.scary_sum(N,a,b,c,e1,e2)<<'\n';}
int main(){ios::sync_with_stdio(0);cin.tie(0);S.init();int T=1;cin>>T;while(T--)solve();}