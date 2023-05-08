#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
const ll p10[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
void solve(){
    ll n,m,a,b;cin>>n>>m>>a>>b;
    ll v=0;
    for(ll i=b;i;i/=10)v+=p10[i%10];
    for(ll i=a;i;i/=10)v-=p10[i%10];
    for(ll i=(n/a+(n%a>0))*b;i<=m;i+=b){
        ll v1=0,v2=0;
        for(ll j=i/b*a;j;j/=10)v1+=p10[j%10];
        for(ll j=i;j;j/=10)v2+=p10[j%10];
        if(v2-v1==v)cout<<i/b*a<<' '<<i<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}