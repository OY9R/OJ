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
    VL a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)a[i]=abs(a[i]);
    ll sum=0;
    for(int i=0;i<n;i++)sum+=a[i];
    ll ans=0;
    for(int i=0;i<n;i++)
        ans+=sum+a[i]*n;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}