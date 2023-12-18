//(ex)CRT ex在于模数间不一定互质
//CRT test:https://www.luogu.com.cn/problem/P1495
//exCRT test:https://www.luogu.com.cn/problem/P4777
#include<iostream>
using namespace std;
typedef long long ll;
struct Excrt
{
    ll _gcd(ll a,ll b){if(a<b)swap(a,b);while(b)a%=b,swap(a,b);return a;}
    ll _lcm(ll a,ll b){return a/_gcd(a,b)*b;}
    ll slowmul(ll a,ll b,ll mod){ 
        ll res=0;a=(a%mod+mod)%mod,b=(b%mod+mod)%mod;
        for(;b;b>>=1,(a<<=1)%=mod)if(b&1)(res+=a)%=mod;return res;}
    void exgcd(ll& a,ll x,ll& b,ll y)//Lemma:abs(a)<=y,abs(b)<=x
    {
        if(y==1){a=0;b=1;return;}//a*(x%y)+a*(x/y)*y+b*y=c*y+d*(x%y)->a*(x/y)+b=c,a=d   
        ll c,d;exgcd(c,y,d,x%y);a=d;b=c-a*(x/y);//abs(c)<=x%y,abs(d)<=y->abs(a)<=y,abs(b)<=x
    }
    bool exgcdp(ll& a,ll x, ll& b,ll y,ll c)//version which b doesn't matter
    {//ax+by=c if ok return 1/a/b else return 0
        ll g= _gcd(x,y);//now T(x)=y/gcd(x,y)
        if (c%g)return 0;x/=g,y/=g,c/=g;//T(origin x)=now y=(*)T(x)
        x>y?exgcd(a,x,b,y):exgcd(b,y,a,x);//cout<<"x"<<x<<"y"<<y<<"a"<<a<<"b"<<b<<'\n';
        a=slowmul(a,c,y);return 1;/*a*=c;b*=c;will overflow when max(a,b)^2>1e18)*/  
    }
    pair<ll,ll>excrt(pair<ll,ll>pa,pair<ll,ll>pb)
    {//pa={a,c},pb={b,d}|t%a=c,t%b=d->ax%b=d-c,ax+by=d-c,(*)T(x)=b/gcd(a,b)
        if(!pa.first||!pb.first)return {0,0};ll x,y;//t=ax+c<=a(*)T(x)+c,
        if(!exgcdp(x,pa.first,y,pb.first,pb.second-pa.second))return {0,0};
        return {_lcm(pa.first,pb.first),pa.first*x+pa.second};//x modified already
    }
}Exc;
void solve()
{
    pair<ll,ll>ans={1,0},b;int n;cin>>n;
    while(n--)cin>>b.first>>b.second,ans=Exc.excrt(ans,b);
    cout<<ans.second<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;//cin >> t;
    while (t--)solve();
}