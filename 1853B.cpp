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
    ll n,k;cin>>n>>k;
    ll ans=0;
    for(int i=n>>1,j;i<=n;i++){j=k-2;
        // cout<<i<<' ';
        for(ll a=i,b=n;j>0;j--){
            b=b-a;
            // cout<<b<<' ';
            if(b>a||b<0)break;
            swap(a,b);
        }
        if(j==0)ans++;
        // cout<<endl;
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