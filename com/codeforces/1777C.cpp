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
const int INF=0x3f3f3f3f,mod=1e9+7,N=100001;
VL mm[N+1];
void init(){
    for(ll i=1;i<=N;i++)
        for(ll j=i;j<=N;j+=i)
            mm[j].pb(i);
}
void solve(){
    ll n,m;cin>>n>>m;
    VL a(n),b(m+1);
    rep(i,0,n)cin>>a[i];
    sort(all(a));
    ll l=0,ans=INF,cnt=0;
    rep(r,0,n){
        rep(i,0,mm[a[r]].size()){
            if(mm[a[r]][i]>m)break;
            if(!b[mm[a[r]][i]]++)cnt++;
        }
        while(cnt==m){
            ans=min(a[r]-a[l],ans);
            rep(i,0,mm[a[l]].size()){
                if(mm[a[l]][i]>m)break;
                if(--b[mm[a[l]][i]]==0)cnt--;
            }l++;
        }
    }
    if(ans==INF)cout<<-1<<endl;
    else cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    init();
    int n;cin>>n;
    while(n--)solve();
    return 0;
}