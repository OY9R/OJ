//source:https://www.cnblogs.com/newera/p/10076871.html
//test:https://www.luogu.com.cn/problem/P3803
//拆系数FFT
#include <bits/stdc++.h>
using namespace std;using ll=long long;const double pi=acos(-1);
struct scomplex{
    double a,b;scomplex(double _a=0,double _b=0){a=_a;b=_b;}
    scomplex operator+(scomplex y){return scomplex(a+y.a,b+y.b);}
    scomplex operator-(scomplex y){return scomplex(a-y.a,b-y.b);}
    scomplex operator*(scomplex y){return scomplex(a*y.a-b*y.b,a*y.b+b*y.a);}};
struct divFFT{//可多测//ans<1e18
    int n,m,bit,bitnum;vector<int>rev;vector<scomplex>a,b,w,t1,t2,t3;   
    void prew(int n){bitnum=0;for(bit=1;bit<=n;bit<<=1)bitnum++;
        a.assign(bit,scomplex());b.assign(bit,scomplex());w.resize(bit);
        t1.resize(bit);t2.resize(bit);t3.resize(bit);rev.resize(bit);
        for(int i=0;i<bit;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bitnum-1)),
            w[i]=scomplex(cos(2*pi*i/bit),sin(2*pi*i/bit));}
    void FFT(vector<scomplex>&s,int op){//op=1:FFT op=-1:IFFT
        for(int i=0;i<bit;i++)if(i<rev[i])swap(s[i],s[rev[i]]);
        for(int len=1;len<bit;len<<=1)for(int st=0,cur=0;st<bit;st+=(len<<1),cur=0)
            for(int k=st;k<st+len;k++,cur=(cur+op*bit/(len<<1)+bit)&(bit-1))
            {scomplex x=s[k],y=w[cur]*s[k+len];s[k]=x+y;s[k+len]=x-y;}
        if(op==-1)for(int i=0;i<bit;i++)s[i]=floor(s[i].a/bit+0.5);}
    vector<ll>GetMul(vector<scomplex>&a,vector<scomplex>&b){FFT(a,1);FFT(b,1);
        for(int i=0;i<bit;i++){scomplex d1,d2,d3,d4;int j=(bit-i)&(bit-1);
            d1=(a[i]+scomplex(a[j].a,-a[j].b))*scomplex(0.5,0);
            d2=(a[i]-scomplex(a[j].a,-a[j].b))*scomplex(0,-0.5);
            d3=(b[i]+scomplex(b[j].a,-b[j].b))*scomplex(0.5,0);
            d4=(b[i]-scomplex(b[j].a,-b[j].b))*scomplex(0,-0.5);
            t1[i]=d1*d3;t2[i]=d1*d4+d2*d3;t3[i]=d2*d4;}
        for(int i=0;i<bit;i++)b[i]=t2[i],a[i]=t1[i]+t3[i]*scomplex(0,1);
        FFT(a,-1);FFT(b,-1);vector<ll>res(n+m+1);for(int i=0;i<=n+m;i++)
            {ll k1=(ll)a[i].a,k2=(ll)b[i].a,k3=(ll)floor(a[i].b/bit+0.5);
                res[i]=((k3<<30)+(k2<<15)+k1);}return res;}
    vector<ll>solve(vector<ll>&aa,vector<ll>&bb){
        n=aa.size()-1,m=bb.size()-1;prew(n+m);//!!!
        for(int i=0;i<=n;i++)a[i]=scomplex(aa[i]&32767,aa[i]>>15);
        for(int i=0;i<=m;i++)b[i]=scomplex(bb[i]&32767,bb[i]>>15);return GetMul(a,b);}}K;
void solve(){int n,m;cin>>n>>m;
    vector<ll>a(n+1),b(m+1);for(auto&k:a)cin>>k;for(auto&k:b)cin>>k;
    vector<ll>c=K.solve(a,b);for(auto k:c)cout<<k<<' ';cout<<'\n';}
int main(){ios::sync_with_stdio(0);cin.tie(0);int t=1;/*cin>>t;*/while(t--)solve();}

