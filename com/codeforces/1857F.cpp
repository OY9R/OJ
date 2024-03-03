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
    map<ll,ll> mp;
    int n;cin>>n;
    rep(i,0,n){
        ll x;cin>>x;
        mp[x]++;
    }
    int m;cin>>m;
    while(m--){
        ll x,y;cin>>x>>y;
        ll d=x*x-y*4;
        if(d<0){
            cout<<0<<endl;
            continue;
        }
        ll p=sqrtl(d);
        if(p*p==d){
            ll a1=p+x;
            ll b1=-(p-x);
            ll ans=0;
            if(a1%2==0&&b1%2==0){
                a1/=2,b1/=2;
                if(a1==b1)ans+=mp[a1]*(mp[a1]-1)/2;
                else ans+=mp[a1]*mp[b1];
            }
            cout<<ans<<' ';
        }else cout<<0<<' ';
    }cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}