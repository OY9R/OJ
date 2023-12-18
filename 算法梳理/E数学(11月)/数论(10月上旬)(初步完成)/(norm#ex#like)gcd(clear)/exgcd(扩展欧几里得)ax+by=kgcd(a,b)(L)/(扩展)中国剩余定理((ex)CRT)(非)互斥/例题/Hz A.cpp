//https://codeforces.com/gym/104090/problem/A
//https://codeforces.com/gym/104090/submission/226699852
#include<iostream>
#include<set>
#include<map>
#include<vector>
typedef long long ll;
using namespace std;
ll _gcd(ll a,ll b){if(a<b)swap(a, b);while(b)a%=b,swap(a,b);return a;}
void exgcd(ll& a,ll x,ll& b,ll y)//abs(a)<=y,abs(b)<=x
{
    if(y==1){a=0;b=1;return;}//a*(x%y)+a*(x/y)*y+b*y=c*y+d*(x%y)->a*(x/y)+b=c,a=d   
    ll c,d;exgcd(c,y,d,x%y);a=d;b=c-a*(x/y);//abs(c)<=x%y,abs(d)<=y->abs(a)<=y,abs(b)<=x
}
void exgcdp(ll& a,ll x,ll& b,ll y,ll mod)//a*x+b*y=1(%mod) x,y!=0
{
    ll g=_gcd(x,y);x/=g,y/=g;
    (x>y)?exgcd(a,x,b,y):exgcd(b,y,a,x);
    a=(a%mod+mod)%mod;b=(b%mod+mod)%mod;
}
void solve() 
{   
    ll n,m,sum=0,st,s,d,mag;cin>>n>>m;ll a=n%m,b=1ll*n*(n+1)/2%m;    
    while (n--)cin>>st,sum+=st;sum%=m;//minimize (sum+mag(a*s+b*d))%m(=ans1)
    if (!a&&!b){cout<<sum<<"\n0 0\n";return;}
    ll cc=_gcd(a,b),c=_gcd(cc,m);ll ans1=sum%c;sum=(ans1-sum+m)%m;//mag(a*s+b*d)=sum(%m)
    exgcdp(s,a,d,b,m);//cc=a*s+b*d(%m),mag*cc=sum(%m)
    exgcdp(mag,cc,st,m,m);//mag*cc+st*m=c(%m)
    (mag*=(sum/c))%=m;cout<<ans1<<'\n'<<s*mag%m<<' '<<d*mag%m<<'\n';
}
int main() 
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
}