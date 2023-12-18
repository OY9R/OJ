//大数分解板子
//blog:https://www.cnblogs.com/Doggu/p/MillerRabin_PollardRho.html
//test:https://www.luogu.com.cn/record/128599119
//miller_rabbin 判大质数 费马小定理检验|polland-rho 找大数的因子 生日悖论
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=998244353;
ll poww(ll bs,ll x){ll ans=1;for(bs=(bs%M+M)%M;x;x>>=1,(bs*=bs)%=M)if(x&1)(ans*=bs)%=M;return ans; }
ll invv(ll bs){return poww(bs,M-2);}
struct disolve1e18{
    ll delt;vector<int>pris={2,3,5,7,11,13};
    ll mul(ll a,ll b,ll m){ll res=0;for(;b;(a<<=1)%=m,b>>=1)if(b&1)(res+=a)%=m;return res;}
    ll f(ll x,ll n){return (mul(x,x,n)+delt)%n;}//随机性能优异
    ll _gcd(ll a,ll b){if(a<b)swap(a,b);while(b)a%=b,swap(a,b);return a;}
    ll powm(ll bs,ll x,ll m){ll res=1;for(;x;x>>=1,bs=mul(bs,bs,m))if(x&1)res=mul(res,bs,m);return res;}   
    bool miller_rabbin(ll n){//is pri->true
        for(auto k:pris)if(n%k==0)return (n==k);ll b=n-1;int cnt=0;while(!(b&1))cnt++,b>>=1;
        for(int i=2;i<=min(n-1,20ll);i++){ll val=powm(i,b,n);for(int j=0;j<cnt;j++)
            {ll v2=mul(val,val,n);if(v2==1&&val!=1&&val!=n-1)return 0;val=v2;}if(val!=1)return 0;}return 1;}
    int find_factorplus(ll n){//“floyd判圈”算法 
        for(ll a=2,b=f(a,n);a!=b;a=f(a,n),b=f(f(b,n),n)){ll p=_gcd(abs(b-a),n);if(p>1)return p;}return 0;}
    vector<ll> disolve(ll _n){
        ll n,n2;n=_n;n2=n;vector<ll>facs;if(n==1)return facs;queue<ll>fds;fds.push(n);
        for(ll x;!fds.empty();fds.pop()){ x=fds.front();if(x==1)continue; while(!miller_rabbin(x))for(delt=2;;delt++)
            {ll fac=find_factorplus(x);if(fac){fds.push(fac);x/=fac;break;}}if(x>1)facs.push_back(x);}
        sort(facs.begin(),facs.end());return facs;}
}mil;
void solve(){ll n;cin>>n;n--;vector<ll>fas=mil.disolve(n);}
int main(){ios::sync_with_stdio(0);cin.tie(0);solve();}