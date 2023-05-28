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
    VL a(n+1),b(n+1);
    bool zero=0;
    rep(i,1,n+1)cin>>a[i];
    rep(i,2,n+1)b[i]=a[i]-a[i-1],zero=zero||b[i];
    if(zero==0){
        cout<<1<<endl;
        return;
    }
    ll ans=0,flag=b[2];
    for(int i=3;i<=n;i++){
        // cout<<b[i]<<' ';
        if(b[i]==0)ans++;
        else {
            if(b[i]*flag>=0)ans++;
            flag=b[i];
        }
    }
    cout<<n-ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}