//https://ac.nowcoder.com/acm/contest/66443/J
#include<iostream>
#include<set>
#include<map>
#include<vector>
typedef long long ll;
using namespace std;
const int M=1e9+7;
map<char,int>mp;
void matmul(vector<vector<ll> >&a,vector<vector<ll> >b)
{
    vector<vector<ll> >c(7,vector<ll>(7,0));
    for(int i=0;i<7;i++)for(int j=0;j<7;j++)for(int k=0;k<7;k++)(c[i][j]+=a[i][k]*b[k][j]%M)%=M;a=c;
}
vector<vector<ll> >powm(vector<vector<ll> >&b,int x)
{    
    vector<vector<ll> >res(7,vector<ll>(7,0));for(int i=0;i<=6;i++)res[i][i]=1;
    for(;x;x>>=1,matmul(b,b))if(x&1)matmul(res,b);return res;
}
void solve() 
{   
    vector<vector<ll> >bs(7,vector<ll>(7,1));for(int i=0;i<=6;i++)bs[i][0]=0;
    ll n,m;cin>>n>>m;while(m--){char a,b;cin>>a>>b;bs[mp[a]][mp[b]]=0;}
    auto res=powm(bs,n);ll ans=0;for(auto k:res[0])(ans+=k)%=M;cout<<ans<<'\n';
}
int main() 
{
    mp['M']=1;mp['O']=2;mp['N']=3;mp['I']=4;mp['K']=5;mp['A']=6;
    ios::sync_with_stdio(0);cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
}