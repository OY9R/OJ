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
const int INF=0x3f3f3f3f,mod=998244353;
ll qmi(ll m,ll k){
    ll res=1,t=m;
    while(k){
        if(k&1)res=res*t%mod;
        t=t*t%mod;
        k>>=1;
    }
    return res;
}
void solve(){
    ll n,k;cin>>n>>k;
    vector<ll> a(n);
    for(ll &i:a)cin>>i;
    sort(all(a));
    ll ans=0,tmp=0;
    for(int i=0;i<n;i++){
        ans=(ans+qmi(a[i],k)*((tmp+a[i])%mod)%mod)%mod;
        tmp=((tmp<<1)%mod+a[i])%mod;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}