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
    int n,p;cin>>n>>p;
    VL a(n),b(p),c(p);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ll t=a[i]*a[j];
            c[t%p]++;
            b[(t+a[i])%p]--;
            b[(t+a[j])%p]--;
        }
    }
    for(int i=0;i<p;i++){
        if(c[i])
        for(int j=0;j<n;j++){
            b[(i+a[j])%p]+=c[i];
        }
    }
    for(int i=0;i<p;i++){
        cout<<b[i]*2<<' ';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}