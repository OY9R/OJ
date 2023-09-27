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
	int n;cin>>n;
    VI a(n),b(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)cin>>b[i];
    rep(i,0,n)a[i]-=b[i];
    vector<PII> v;
    rep(i,0,n)v.pb(mp(a[i],i+1));
    sort(all(v));
    VI ac;ac.pb(v[n-1].se);
    per(i,0,n-1)if(v[i].fi==v[n-1].fi)ac.pb(v[i].se);
    reverse(all(ac));
    cout<<ac.size()<<endl;
    for(auto i:ac)cout<<i<<" ";
    cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}