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
    int n,ans=0;cin>>n;
    VI b(n);for(auto &i:b)cin>>i;
    VI premx(n),sufmx(n);
    rep(i,0,n)premx[i]=b[i]+i,sufmx[i]=b[i]-i;
    rep(i,1,n)premx[i]=max(premx[i],premx[i-1]);
    per(i,0,n-1)sufmx[i]=max(sufmx[i],sufmx[i+1]);
    rep(m,1,n-1)ans=max(ans,b[m]+premx[m-1]+sufmx[m+1]);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}