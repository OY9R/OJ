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
	int n,m;ll k,h;cin>>n>>m>>k>>h;
    VL a(n);
    rep(i,0,n)cin>>a[i];
    rep(i,0,n)a[i]=abs(a[i]-h);
    int ans=0;
    rep(i,0,n)if(a[i]%k==0&&a[i]<=(m-1)*k&&a[i]!=0){
        ans++;
        // cout<<i+1<<' ';
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