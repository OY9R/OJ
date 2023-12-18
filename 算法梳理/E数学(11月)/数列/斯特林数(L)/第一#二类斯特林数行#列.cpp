//第一#二类斯特林数行#列 https://www.luogu.com.cn/blog/ACCOTY/si-te-lin-fan-yan
#include<bits/stdc++.h>
using namespace std;using ll=long long;const int M=167772161,g=3;
struct calcC
{//precal needed
    ll poww(ll bs,ll x) { ll res=1;for(;x;x>>=1,(bs*=bs)%=M)if(x&1)(res*=bs)%=M;return res; }
    ll invv(ll bs) { return poww(bs,M-2); }vector<ll>mul,inv;
    void precal(int P)
    {
        mul.resize(P+1);mul[0]=1;for(int i=1;i<=P;i++)mul[i]=mul[i-1]*i%M;
        inv.resize(P+1);inv[P]=invv(mul[P]);for(int i=P;i;i--)inv[i-1]=inv[i]*i%M;
    }
    ll C(int n,int m) { if(n<m)return 0;return mul[n]*inv[m]%M*inv[n-m]%M; }
}xC;
struct NTT{//998244352=1048576*8*119//或P=1004535809//可多测//ans<M(1e9)
    int bit,bitnum=0;vector<int>rev,w;
    int poww(ll a,int b){ll ans=1;for(;b;b>>=1,a=a*a%M)if(b&1)(ans*=a)%=M;return ans;}
    int invv(ll a){return poww(a,M-2);}
    void prew(int n){bitnum=0;for(bit=1;bit<=n;bit<<=1)bitnum++;
        rev.resize(bit,0);w.resize(bit,0);w[0]=1;int bs=poww(3,(M-1)/bit);
        for(int i=1;i<bit;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bitnum-1)),w[i]=1ll*w[i-1]*bs%M;}
    void _NTT(vector<int>&s,int op){//cur*op:IFFT A/reverse(s+1,s+bit):IFFT B
        for(int i=0;i<bit;i++)if(i<rev[i])swap(s[i],s[rev[i]]);int x,y;
        for(int len=1;len<bit;len<<=1)for(int st=0,cur=0,dst=(len<<1),dc=op*bit/(len<<1)+bit;st<bit;st+=dst,cur=0)
            for(int k=st;k<len+st;k++,cur=(cur+dc)&(bit-1))x=s[k],y=ll(s[k+len])*w[cur]%M,s[k]=(x+y)%M,s[k+len]=(x-y+M)%M;
        if(op==-1){int inv=poww(bit,M-2);for(int i=0;i<bit;i++)s[i]=ll(s[i])*inv%M;}}
    vector<int>mul(vector<int>a,vector<int>b,int l=0){
        int n=a.size(),m=b.size();prew(n+m-1);a.resize(bit,0);b.resize(bit,0);
        _NTT(a,1);_NTT(b,1);for(int i=0;i<bit;i++)a[i]=ll(a[i])*b[i]%M;_NTT(a,-1);a.resize(l?l:n+m-1);return a;}
    vector<int>inv(vector<int>&a,int l=0){//a[0]!=0//%(x^l)//保留l项
        int asiz=int(a.size()),lstsz=1;if(!l)l=asiz;vector<int>b(1,0);b[0]=poww(a[0],M-2);
        vector<int>sr;for(int x=l;x>1;x=(x+1)/2)sr.push_back(x);reverse(sr.begin(),sr.end());for(auto siz:sr){//省时
            int asl=min(siz,asiz);prew((lstsz<<1)+asl-1);b.resize(bit,0);
            vector<int>a2(bit,0);for(int i=0;i<asl;i++)a2[i]=a[i];_NTT(b,1);_NTT(a2,1);
            for(int i=0;i<bit;i++)b[i]=(ll)b[i]*(2-(ll)a2[i]*b[i]%M+M)%M;_NTT(b,-1);b.resize(siz);lstsz=siz;}return b;}
    vector<int>div(vector<int>&a,vector<int>&b,int l=0){int n=a.size(),m=b.size();if(!l)l=max(n,m);
        vector<int>invb=inv(b,l),c=mul(a,invb);c.resize(l);return c;}
    vector<int>GetDerivation(vector<int>&a){int siz=int(a.size());
        vector<int>res(siz-1,0);for(int i=1;i<siz;i++)res[i-1]=ll(a[i])*i%M;return res;}
    vector<int>GetIntegral(vector<int>&a){int siz=int(a.size());
        vector<int>res(siz+1,0);for(int i=1;i<siz;i++)res[i]=ll(a[i-1])*invv(i)%M;return res;}
    vector<int>ln(vector<int>a,int l=0){if(!l)l=int(a.size());a.resize(l,0);//a[0]=1 only
        vector<int>ad=GetDerivation(a),pr=div(ad,a),res=GetIntegral(pr);res.resize(l);return res;}
    vector<int>exp(vector<int>&a,int l=0){//a[0]=0 only
        int asiz=int(a.size()),lstsz=1;if(!l)l=asiz;vector<int>b(1,1);
        vector<int>sr;for(int x=l;x>1;x=(x+1)/2)sr.push_back(x);reverse(sr.begin(),sr.end());for(auto siz:sr){    
            prew(siz<<1);b.resize(bit,0);vector<int>a2(bit,0);for(int i=0;i<min(siz,asiz);i++)a2[i]=a[i];a2[0]++;
            vector<int>lnb0=ln(b,siz);for(int i=0;i<siz;i++)a2[i]=(a2[i]-lnb0[i]+M)%M;b=mul(b,a2);b.resize(siz);lstsz=siz;}return b;}
    vector<int>poww(vector<int>&a,ll s,int n=0){
        int p1=s%M,p2=s%(M-1),siz=int(a.size()),lst=-1;if(!n)n=siz;
        vector<int>res(n,0);if(!s){res[0]=1;return res;}
        for(int i=n-1;i>=0;i--)if(a[i])lst=i;if(lst==-1||ll(lst)*p1>=n||(lst&&s>n))return res;
        int val=a[lst],iv=invv(val),pw=poww(val,p2);vector<int>a2(n-lst,0);for(int i=0;i<n-lst;i++)a2[i]=ll(a[i+lst])*iv%M;
        vector<int>b=ln(a2);for(auto &k:b)k=ll(k)*p1%M;vector<int>c=exp(b);
        for(int i=0,d=lst*p1;i<n-d;i++)res[i+d]=ll(c[i])*pw%M;return res;}    
}K;
vector<int>Stiring_A_row(int n){//上升幂&&第一类斯特林行//P5408
    if(n==1)return{0,1};int sz=n>>1;
    vector<int>F=Stiring_A_row(sz),a(sz+1,0);for(int i=0;i<=sz;i++)a[i]=ll(F[i])*xC.mul[i]%M;
    vector<int>b(sz+1,0);for(int i=0,B=1;i<=sz;i++)b[sz-i]=ll(B)*xC.inv[i]%M,B=(ll)B*sz%M;
    vector<int>c=K.mul(a,b),G(sz+1);for(int i=0;i<=sz;i++)G[i]=ll(c[i+sz])*xC.inv[i]%M;F=K.mul(F,G);
    if(n&1){for(auto &k:F)k=ll(k)*(n-1)%M;F.push_back(0);
        int iv=xC.invv(n-1);for(int i=n;i;i--)(F[i]+=ll(F[i-1])*iv%M)%=M;}return F;}
vector<int>Stiring_A_col(int n,int k){//第一类斯特林列//P5409
    vector<int>F(n+1,0);if(n<k)return F;for(int i=1;i<=n;i++)F[i]=xC.invv(i);
    auto R=K.poww(F,k);for(auto &kk:R)kk=ll(kk)*xC.inv[k]%M;
    vector<int>res(n+1,0);for(int i=0;i<=n;i++)res[i]=ll(R[i])*xC.mul[i]%M;return res;}
vector<int>Stiring_B_row(int n){//第二类斯特林行//P5395
    vector<int>F(n+1,0);for(int i=0;i<=n;i++)F[i]=ll(xC.inv[i])*((i&1)?M-1:1)%M;
    vector<int>G(n+1,0);for(int i=0;i<=n;i++)G[i]=ll(xC.inv[i])*xC.poww(i,n)%M;
    auto res=K.mul(F,G);res.resize(n+1);return res;}
vector<int>Stiring_B_col(int n,int k){//第二类斯特林列//P5396
    vector<int>F(n+1,0);if(n<k)return F;for(int i=1;i<=n;i++)F[i]=xC.inv[i];
    auto R=K.poww(F,k);for(auto &kk:R)kk=ll(kk)*xC.inv[k]%M;
    vector<int>res(n+1,0);for(int i=0;i<=n;i++)res[i]=ll(R[i])*xC.mul[i]%M;return res;}
void solve_Stiring_A_row(){int n;cin>>n;vector<int>res=Stiring_A_row(n);for(auto k:res)cout<<k<<' ';}
void solve_Stiring_A_col(){int n,k;cin>>n>>k;vector<int>res=Stiring_A_col(n,k);for(auto k:res)cout<<k<<' ';}
void solve_Stiring_B_row(){int n;cin>>n;vector<int>res=Stiring_B_row(n);for(auto k:res)cout<<k<<' ';}
void solve_Stiring_B_col(){int n,k;cin>>n>>k;vector<int>res=Stiring_B_col(n,k);for(auto k:res)cout<<k<<' ';}
int main(){ios::sync_with_stdio(0);cin.tie(0);xC.precal(3e5);solve_Stiring_B_col();}
