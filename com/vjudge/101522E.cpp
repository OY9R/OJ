#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int n;cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll sum=0;
    for(int i=1;i<n;i++)sum+=abs(a[i]-a[i-1]);
    for(int i=0;i<n-1;i++)b[i]=abs(-a[i+1]-a[i])-abs(a[i+1]-a[i]);
    sort(all(b));
    cout<<min({sum,sum+b[0],sum+b[1],sum+b[0]+b[1]});
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}