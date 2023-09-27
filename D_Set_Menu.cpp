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
void solve(){
	ll n,m,p,ans=0;cin>>n>>m>>p;
	vector<ll> a(n),b(m);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i];
    ll sum=0;
    sort(all(a));
    sort(all(b));
    reverse(all(a));
    int j=0;
    for(int i=0;i<n;i++)sum+=a[i];
    for(int i=0;i<m;i++){
        while(j<n&&b[i]+a[j]>=p)sum-=a[j],j++;
        // cout<<b[i]<<' '<<sum<<'+'<<j*p<<endl;
        ans+=sum+b[i]*(n-j)+j*p;
    }
    cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}