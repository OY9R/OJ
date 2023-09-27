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
    vector<ll> ss(m);
    for(ll &s:ss){
        int k;cin>>k;
        rep(i,0,k){
            int x;cin>>x;
            s|=1L<<(x-1);
        }
    }
    ll ans=0;
    for(ll i=1,s=0;i<(1<<m);i++,s=0){
        for(int j=0;j<m;j++)
            if(i&(1<<j))
                s|=ss[j];
        if(s==(1L<<n)-1)ans++;
    }
    cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}