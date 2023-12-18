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
const int N=1000001;
ll a[N+1],p[N+1],f[N+1];
ll inv(ll a){
    return a<=1?1:(mod-mod/a)*inv(mod%a)%mod;
}
void solve(){
    p[0]=1;
    rep(i,1,N+1)p[i]=(p[i-1]<<1)%mod;
	ll n,t,ans=0,mul=1;cin>>n;
    rep(i,0,n)cin>>t,a[t]++,mul=mul*t%mod;
    rep(i,1,N+1){
        for(int j=(t=0,i);j<=N;j+=i)t+=a[j];
        f[i]=p[t]-1;
    }
    per(i,1,N+1){
        for(int j=i+i;j<=N;j+=i)f[i]=(f[i]-f[j]+mod)%mod;
        ans=(ans+mul*inv(i)%mod*f[i]%mod)%mod;
    }
    cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}