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
ll t,n,a[2000005],pre[2000005];
void solve(){
    int n;cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    ll l=1,r=n,ans=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        cout<<"? "<<mid-l+1<<' ';
        rep(i,l,mid+1)cout<<i<<' ';
        cout<<endl<<flush;
        ll x;cin>>x;
        if(x==pre[mid]-pre[l-1])l=mid+1;
        else r=mid-1,ans=mid;
    }
    cout<<"! "<<ans<<endl<<flush;
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}