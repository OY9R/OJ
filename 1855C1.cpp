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
    VL a(n+1);
    rep(i,1,n+1)cin>>a[i];
    VL b=a;
    int maxi=1;
    rep(i,1,n+1)if(a[i]>a[maxi])maxi=i;
    vector<PII> ans;
    while(a[n]<=0){
        cout<<a[n]<<' '<<a[maxi]<<endl;
        a[n]+=a[maxi];
        ans.pb(mp(n,maxi));
    }
    // rep(i,2,n+1){
    //     if(a[i]<a[i-1]){
    //         while(a[i]+a[n]<a[i-1]&&a[n]<=INF){
    //             a[n]+=a[n];
    //             ans.pb(mp(n,n));
    //         }
    //         a[i]+=a[n];
    //         ans.pb(mp(i,n));
    //     }
    // }
    // rep(i,1,n+1)cout<<a[i]<<' ';cout<<endl;
    // cout<<ans.size()<<endl;
    // for(auto i:ans)cout<<i.fi<<' '<<i.se<<endl;
    // cout<<-1<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}