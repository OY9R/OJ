//blog:https://www.cnblogs.com/dcdcbigbig/p/9359329.html
//test:https://www.luogu.com.cn/problem/P3803
//例题:https://codeforces.com/gym/104373/submission/230434896
#include<bits/stdc++.h>
using namespace std;using ll=long long;const int M[3]={469762049,998244353,1004535809},g=3;
struct hyperNTT{//三模数NTT//支持多测//ans<1e18
    int mod;int n,m,bit,bitnum=0;vector<int>a,b,rev,w;
    int poww(ll a,int b){ll ans=1;for(;b;b>>=1,a=a*a%mod)if(b&1)(ans*=a)%=mod;return ans;}
    void prew(int n){bitnum=0;for(bit=1;bit<=n;bit<<=1)bitnum++;a.resize(bit,0);b.resize(bit,0)
        ;rev.resize(bit,0);w.resize(bit,0);w[0]=1;int bs=poww(3,(mod-1)/bit);
        for(int i=1;i<bit; i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bitnum-1)),w[i]=1ll*w[i-1]*bs%mod;}
    void _NTT(vector<int>&s,int op){//cur*op:IFFT A/reverse(s+1,s+bit):IFFT B
        for(int i=0;i<bit;i++)if(i<rev[i])swap(s[i],s[rev[i]]);int x,y;
        for(int len=1;len<bit;len<<=1)for(int st=0,cur=0,dst=(len<<1),dc=op*bit/(len<<1)+bit;st<bit;st+=dst,cur=0)
            for(int k=st;k<len+st;k++,cur=(cur+dc)&(bit-1))x=s[k],y=ll(s[k+len])*w[cur]%M,s[k]=(x+y)%M,s[k+len]=(x-y+M)%M;
        if(op==-1){int inv=poww(bit,M-2);for(int i=0;i<bit;i++)s[i]=ll(s[i])*inv%M;}}
    void Getmul(){_NTT(a,1);_NTT(b,1);for(int i=0;i<bit;i++)a[i]=ll(a[i])*b[i]%mod;_NTT(a,-1);}
    vector<int>solve(vector<int>&aa,vector<int>&bb,int MM){a=aa;b=bb;mod=MM;
        n=a.size();m=b.size();prew(n+m-1);Getmul();a.resize(n+m-1);return a;}
    ll poww(ll a,ll b,ll m){ll ans=1;for(;b;b>>=1,(a*=a)%=m)if(b&1)(ans*=a)%=m;return ans; }
    ll inv(ll a,ll m){return poww(a,m-2,m);}ll mul(ll a,ll b,ll MOD){        
        ll ret=0;for(a=(a%MOD+MOD)%MOD,b=(b%MOD+MOD)%MOD;b;
            b>>=1,a=(a+a)%MOD)if(b&1)(ret+=a)%=MOD;return ret;}
    vector<ll>Solve(vector<int>&a,vector<int>&b,ll S=2e18){
        vector<vector<int>>c(3);for(int i=0;i<3;i++)c[i]=solve(a,b,M[i]);
        vector<ll>res(n+m-1,0);for(int i=0;i<=n+m-2;i++)
        {ll L=ll(M[0])*M[1],X=mul(ll(c[0][i])*M[1],inv(M[1],M[0]),L),
            Y=mul(ll(c[1][i])*M[0],inv(M[0],M[1]),L),A=(X+Y)%L;
        ll K=mul(-A+c[2][i],inv(L,M[2]),M[2]);res[i]=(mul(K,L,S)+A%S)%S;}return res;}}K;
void solve(){int n,m;cin>>n>>m;vector<int>a(n+1),b(m+1);for(auto&k:a)cin>>k;for(auto&k:b)cin>>k;
    vector<ll>res=K.Solve(a,b);for(auto k:res)cout<<k<<' ';}
int main(){ios::sync_with_stdio(0);cin.tie(0);int t=1;/*cin>>t;*/while(t--)solve();}

