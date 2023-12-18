//exgcd(ax+by=gcd(a,b)/c)
//test:https://www.luogu.com.cn/record/128086255
#include<iostream>
using namespace std;
typedef long long ll;
ll _gcd(ll a,ll b){if(a<b)swap(a,b);while(b)a%=b,swap(a,b);return a;}
ll _lcm(ll a,ll b){return a/_gcd(a,b)*b;}
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
    a*=c;b*=c;return 1;/*a*=c;b*=c;will overflow when max(a,b)^2>1e18)*/  
}
void solve()
{
    ll x,y,a,b,c;cin>>x>>y>>c;ll l=_lcm(x,y),Ta=l/x,Tb=l/y;//a+=Ta,b-=Tb
    if(!exgcdp(a,x,b,y,c)){cout<<"-1\n";return;}ll cnt,ami,bmi,ama,bma,T;
    ami=((a-1)%Ta+Ta)%Ta+1,T=(a-ami)/Ta,bma=b+T*Tb;bmi=((b-1)%Tb+Tb)%Tb+1,T=(b-bmi)/Tb,ama=a+T*Ta;
    if(bma<=0)cout<<ami<<' '<<bmi<<'\n';else cout<<(ama-ami)/Ta+1<<' '<<ami<<' '<<bmi<<' '<<ama<<' '<<bma<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
}