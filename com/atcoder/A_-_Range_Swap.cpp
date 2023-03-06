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
    int n,p,q,r,s;cin>>n>>p>>q>>r>>s;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=p;i<=q;i++){
        swap(a[i-p+r],a[i]);
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}