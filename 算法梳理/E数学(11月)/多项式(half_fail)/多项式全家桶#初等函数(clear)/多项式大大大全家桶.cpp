//多项式全家桶
//https://www.cnblogs.com/dcdcbigbig/p/9359329.html
#include<bits/stdc++.h>//https://www.luogu.com.cn/problem/P3803
using namespace std;using ll=long long;const int M=998244353,g=3;
struct Cipolla{//a^2=x(%P)
	struct cp{ll x,y;int w,mod;cp(ll _x,ll _y,int _w,int P){x=_x,y=_y;w=_w;mod=P;}//x+y*sqrt(w)(%P)
        inline cp operator*(const cp&b)const{return cp((x*b.x+w*y%mod*b.y)%mod,(x*b.y+y*b.x)%mod,w,mod);}
        inline cp operator*(const int&b)const{return cp((x*b)%mod,(y*b)%mod,w,mod);}};
    ll poww(ll bs,ll x,int P){ll res=1;for(;x;x>>=1,(bs*=bs)%=P)if(x&1)(res*=bs)%=P;return res;}
    int poww(cp x,int y){cp res(1,0,x.w,x.mod);for(;y;y>>=1,x=x*x)if(y&1)res=res*x;return res.x;}
    int Cipo(int x,int P){if(!x)return 0;if(poww(x,(P-1)>>1,P)==P-1)return -1;
    for(int a=1;a<=P>>1;a++){int w=(ll(a)*a-x+P)%P;if(!w)return a;if(poww(w,(P-1)>>1,P)==P-1)
        {int val=poww(cp(a,1,w,P),(P+1)>>1);return min(val,P-val);}}}}Ci;
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
    void mod(vector<int>&a,vector<int>&b,vector<int>&c,vector<int>&d){//a n项/b m项/c n-m+1项/d m-1项
        reverse(a.begin(),a.end());reverse(b.begin(),b.end());int n=a.size(),m=b.size();
        vector<int>invb=inv(b,n);c=mul(a,invb);c.resize(n-m+1);reverse(c.begin(),c.end());
        reverse(a.begin(),a.end());reverse(b.begin(),b.end());d=mul(c,b);
        for(int i=0;i<m-1;i++)d[i]=(a[i]-d[i]+M)%M;d.resize(m-1);}
    vector<int>sqrt(vector<int>&a,int l=0){//a[0]=1:b[0]=1|a[0]!=1:Cipolla
        int asiz=int(a.size()),lstsz=1;if(!l)l=asiz;vector<int>b(1,0);b[0]=Ci.Cipo(a[0],M);
        vector<int>sr;for(int x=l;x>1;x=(x+1)/2)sr.push_back(x);reverse(sr.begin(),sr.end());for(auto siz:sr){//省时      
            prew(siz<<1);b.resize(bit,0);vector<int>a2(bit,0);for(int i=0;i<min(siz,asiz);i++)a2[i]=a[i];
            vector<int>c=div(a2,b);b.resize(siz);for(int i=0;i<siz;i++)b[i]=ll(b[i]+c[i])*(M+1)/2%M;lstsz=siz;}return b;}
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
/*P3803*/void solvemul(){int n,m;cin>>n>>m;vector<int>a(n+1),b(m+1);for(auto&k:a)cin>>k;
    for(auto&k:b)cin>>k;vector<int>c=K.mul(a,b);for(auto k:c)cout<<k<<' ';cout<<'\n';}
/*P4238*/void solveinv(){int n;cin>>n;vector<int>a(n);for(auto&k:a)cin>>k;
    vector<int>b=K.inv(a);for(auto k:b)cout<<k<<' ';cout<<'\n';}
/*P4512*/void solvemod(){int n,m;cin>>n>>m;vector<int>a(n+1),b(m+1);for(auto&k:a)cin>>k;for(auto&k:b)cin>>k;
    vector<int>c,d;K.mod(a,b,c,d);for(auto k:c)cout<<k<<' ';cout<<'\n';for(auto k:d)cout<<k<<' ';cout<<'\n';}
/*P5205/5277*/void solvesqrt(){int n;cin>>n;vector<int>a(n);for(auto&k:a)cin>>k;
    vector<int>b=K.sqrt(a);for(auto k:b)cout<<k<<' ';cout<<'\n';}
/*P4725*/void solveln(){int n;cin>>n;vector<int>a(n);for(auto&k:a)cin>>k;
    vector<int>b=K.ln(a);for(auto k:b)cout<<k<<' ';cout<<'\n';}
/*P4726*/void solveexp(){int n;cin>>n;vector<int>a(n);for(auto&k:a)cin>>k;
    vector<int>b=K.exp(a);for(auto k:b)cout<<k<<' ';cout<<'\n';}
/*P5245/5273*/void solvepoww(){int n;ll s;cin>>n>>s;vector<int>a(n);for(auto&k:a)cin>>k;
    vector<int>b=K.poww(a,s);for(auto k:b)cout<<k<<' ';cout<<'\n';}
int main(){//freopen("2.in","r",stdin);
ios::sync_with_stdio(0);cin.tie(0);int t=1;/*cin>>t;*/while(t--)solvepoww(); }
