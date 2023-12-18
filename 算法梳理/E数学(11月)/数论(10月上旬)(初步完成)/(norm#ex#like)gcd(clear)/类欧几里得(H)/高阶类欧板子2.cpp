//¸ß½×ÀàÅ·°å×Ó2
//test:https://loj.ac/p/138
//test2:https://www.luogu.com.cn/problem/P5170
//blog:https://www.cnblogs.com/zzqsblog/p/8904010.html
//cal:sum[0,n]((x^k1)*((a*x+b)/c)^k2)
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int M=998244353,P=2.4e4,S=2;//1e9+7 10
ll poww(ll bs,ll x){ll ans=1;for(;x;x>>=1,(bs*=bs)%=M)if(x&1)(ans*=bs)%=M;return ans;}
ll invv(ll bs){return poww(bs,M-2);}
namespace Lagrange
{
    ll x[P],y[P],a[P],g[P],h[P],p[P]; int N;
    void work()
    {
        for(int i=0;i<N;i++)a[i]=0;g[0]=1;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<=i;j++)h[j+1]=g[j]; h[0]=0;
            for(int j=0;j<=i;j++)(h[j]-=g[j]*i)%=M;
            for(int j=0;j<=i+1;j++)g[j]=h[j];
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<=N;j++)p[j]=g[j];for(int j=N;j;j--)(p[j-1]+=p[j]*x[i])%=M;
            ll s=1;for(int j=0;j<N;j++)if(x[i]!=x[j])(s*=(x[i]-x[j]))%=M;s=y[i]*invv(s)%M;
            for(int j=0;j<N;j++)(a[j]+=p[j+1]*s)%=M;
        }
    }
    vector<int> feed(vector<int> v)
    {
        N=v.size();for(int i=0;i<N;i++)x[i]=i,y[i]=v[i];
        work();v.clear();for(int i=0;i<N;i++) v.push_back(a[i]);
        while(v.size()&&!v.back())v.pop_back();return v;
    }
    ll calc(vector<int>& v,ll x){ll s=0,b=1;x%=M;for(auto k:v)(s+=b*k)%=M,(b*=x)%=M;return s;}//cal F(x)
}
vector<int> ps[2400];//ps[k]=\sum_{i=0}^x i^k
vector<int> rs[2400];//rs[k]=\sum_{i=0}^x ((i+1)^k-i^k)
struct arr{ll p[S+1][S+1];};
ll C[240][240];
arr calc2(ll a,ll b,ll c,ll n)
{
    arr w;if(n==0)a=0;
    if(a==0||a*n+b<c){for(ll i=0;i<=S;i++)for(ll j=0,t=Lagrange::calc(ps[i],n),s=b/c;j<=S-i;j++)w.p[i][j]=t,t=t*s%M;return w;}
    for(int i=0;i<=S;i++)w.p[i][0]=Lagrange::calc(ps[i],n);
    if(a>=c||b>=c){arr t=calc2(a%c,b%c,c,n);ll p=a/c,q=b/c;for(int i=0;i<=S;i++)for(int j=1;j<=S-i;j++)
        {ll s=0,px=1;for(ll x=0;x<=j;x++,(px*=p)%=M)for(ll y=0,qy=1;y<=j-x;y++,(qy*=q)%=M)
            (s+=px*qy%M*C[j][x]%M*C[j-x][y]%M*t.p[i+x][j-x-y])%=M; w.p[i][j]=s;}return w;}
    ll m=(a*n+b)/c;arr t=calc2(c,c-b-1,a,m-1);
    for(int i=0;i<=10;i++)for(int j=1;j<=S-i;j++){ll s=Lagrange::calc(rs[j],m-1)*Lagrange::calc(ps[i],n)%M;//v*t^p*((tc+c-b-1)/a)^q
        for(int p=0;p<j;p++)for(int q=0;q<ps[i].size();q++)(s-=t.p[p][q]*(C[j][p]*ps[i][q]%M))%=M;w.p[i][j]=s;}return w;
}
void solve()
{
    int n,a,b,c;cin>>n>>a>>b>>c;arr res=calc2(a,b,c,n);
    cout<<(res.p[0][1]+M)%M<<' '<<(res.p[0][2]+M)%M<<' '<<(res.p[1][1]+M)%M<<'\n';
}
void precal()
{
    for(int i=0;i<=230;i++)C[i][0]=1;
    for(int i=0;i<=230;i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
    for(int i=0;i<=S;i++)
    {
        ll sp=0,sr=0; vector<int> p,r;
        for(int j=0;j<=2*S;j++)
        {
            (sp+=poww(j,i))%=M,p.push_back(sp);
            (sr+=poww(j+1,i)-poww(j,i))%=M,r.push_back(sr);
        }
        ps[i]=Lagrange::feed(p);rs[i]=Lagrange::feed(r);
    }
}
int main()
{
    precal();int t=1;cin>>t;while(t--)solve();
}