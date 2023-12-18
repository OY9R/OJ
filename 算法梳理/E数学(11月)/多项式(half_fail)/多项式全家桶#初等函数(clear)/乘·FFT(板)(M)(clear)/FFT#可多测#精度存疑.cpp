//source:https://www.cnblogs.com/dcdcbigbig/p/9359329.html
//test:https://www.luogu.com.cn/problem/P3803
//爆精度了:https://codeforces.com/gym/104373/submission/230432113
#include<bits/stdc++.h>
using namespace std;const double pi=acos(-1);
struct scomplex{//friend complex operator -(complex x,complex y){return complex(x.a-y.a,x.b-y.b);}
    double a,b;scomplex(double _a=0,double _b=0){a=_a;b=_b;}
    scomplex operator+(scomplex y){return scomplex(a+y.a,b+y.b);}
    scomplex operator-(scomplex y){return scomplex(a-y.a,b-y.b);}
    scomplex operator*(scomplex y){return scomplex(a*y.a-b*y.b,a*y.b+b*y.a);}
    scomplex operator*(double y){return scomplex(a*y,b*y);}
    scomplex operator/(double y){return scomplex(a/y,b/y);}};
struct FFT{//可多测//精度存疑
    int n,m,bit,bitnum;vector<int>rev;vector<scomplex>a,b,w;
    void prew(int n){bitnum=0;for(bit=1;bit<=n;bit<<=1)bitnum++;rev.resize(bit);
        a.assign(bit,scomplex());b.assign(bit,scomplex());w.resize(bit);
        for(int i=0;i<bit;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(bitnum-1)),
            w[i]=scomplex(cos(2*pi*i/bit),sin(2*pi*i/bit));}
    void _FFT(vector<scomplex>&s,int op){//op=1:FFT op=-1:IFFT
        for(int i=0;i<bit;i++)if(i<rev[i])swap(s[i],s[rev[i]]);
        for(int len=1;len<bit;len<<=1)for(int st=0,cur=0;st<bit;st+=(len<<1),cur=0)
            for(int k=st; k<st+len; k++,cur=(cur+op*bit/(len<<1)+bit)&(bit-1))
            {scomplex x=s[k],y=w[cur]*s[k+len];s[k]=x+y;s[k+len]=x-y;}
        if(op==-1)for(int i=0;i<bit;i++)s[i]=s[i]/(double)bit;}
    void Getmul(){_FFT(a,1);_FFT(b,1);for(int i=0;i<bit;i++)a[i]=a[i]*b[i];_FFT(a,-1);}
    vector<int>solve(vector<int>&aa,vector<int>&bb){n=aa.size();m=bb.size();prew(n+m-1);
        for(int i=0;i<n;i++)a[i].a=aa[i];for(int i=0;i<m;i++)b[i].a=bb[i];Getmul();
        vector<int>res(m+n-1);for(int i=0;i<=m+n-2;i++)res[i]=(int)(a[i].a+0.5*(a[i].a>0));return res;}}K;
void solve(){int n,m;cin>>n>>m;vector<int>a(n+1),b(m+1);for(auto &k:a)cin>>k;for(auto &k:b)cin>>k;
    vector<int>c=K.solve(a,b);for(auto k:c)cout<<k<<' ';cout<<'\n';}
int main(){ios::sync_with_stdio(0);cin.tie(0);int t=1;/*cin>>t;*/while (t--)solve();}