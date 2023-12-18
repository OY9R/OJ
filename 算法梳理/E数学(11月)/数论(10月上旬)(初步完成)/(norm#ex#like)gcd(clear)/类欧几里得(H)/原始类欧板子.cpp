//原始类欧板子
//test:https://www.luogu.com.cn/problem/P5170
//result:https://www.luogu.com.cn/record/128390870
//blog:https://www.cnblogs.com/KatouKatou/p/9745998.html
//cal:sum[0,n](a*x+b)/c
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int M=998244353;
ll likegcd(ll a,ll b,ll c,ll n)
{
    if(n<0||a*n+b<c)return 0;
    if(a>=c||b>=c)
    {
        ll v1=(1ll*n*(n+1)/2%M)*(a/c)%M,v2=(n+1)*(b/c)%M;
        return (likegcd(a%c,b%c,c,n)+v1+v2)%M;
    }
    int f=((a*n)+b)/c;return (n*f-likegcd(c,c-b-1,a,f-1)+M)%M;
}
void solve()
{
    int n,a,b,c;cin>>n>>a>>b>>c;
    cout<<likegcd(a,b,c,n)<<'\n';
}
int main()
{
    int t=1;cin>>t;while(t--)solve();
}