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
int n,k;
VL a,b;
int check(int m){
    ll ret=INF;
    // cout<<m<<":";
    rep(i,0,n){
        if(m>b[i])break;
        ll cnt=0;
        rep(j,i,min(i+m,n)){
            if(a[j]<m-(j-i)){
                cnt+=m-(j-i)-a[j];
            }else break;
        }
        // cout<<cnt<<" ";
        ret=min(ret,cnt);
    }
    // cout<<endl;
    return ret;
}
void solve(){
	cin>>n>>k;
    a.resize(n+1);
    b.resize(n+1);
    rep(i,0,n)cin>>a[i];
    b[n-1]=a[n-1];
    per(i,0,n-1)b[i]=max(a[i],b[i+1]+1);
    // rep(i,0,n)cout<<b[i]<<" ";
    ll ans=0;
    rep(i,0,n)ans=max(ans,a[i]);
    for(int i=ans+1;check(i)<=k;i++){
        // cout<<i<<":"<<check(i)<<endl;
        ans=i;
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