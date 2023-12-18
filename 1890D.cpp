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
void solve()
{ // 抄的
    ll n,c;
    cin >> n >> c;
    vector<pair<ll, ll>> a(n - 1);
    vector<ll> b(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        ll tot;
        cin >> tot;
        if (i != 1)
            a[i - 2] = {tot - i * c, i};
        b[i] = tot;
    }
    sort(a.begin(), a.end(),greater<pair<ll,ll>>());
    ll tot = b[1];
    for (int i = 0; i <= n - 2; ++i)
    {
        
        if (a[i].first + tot < 0)
        {
            cout << "NO" << endl;
            return;
        }
        tot += b[a[i].second];
    }
    cout << "YES" << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}