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
	int n,m;cin>>n>>m;
    VL a(n);
    rep(i,0,n)cin>>a[i];
    ll sum=0;
    sort(all(a));
    rep(i,0,n-m)sum+=a[i];
    ll ans=sum;
    for(int i=n-m;i<n;i++){
        sum=sum+a[i]-a[(i-n+m)*2]-a[(i-n+m)*2+1];
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}