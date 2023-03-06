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
    int n,m;cin>>n>>m;
    VI a(n+1),b(n+1),c(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)b[i]=a[i]+b[i-1];
    int q;cin>>q;
    while(q--){
        int l,r;cin>>l>>r;
        int sum=0,tmp=0;
        for (int i=l;i<=r-m;i++){
            sum+=b[i+m]-b[i- 1];
        }
        cout<<sum<<' ';
        if(sum%m==0)cout<<"Yes\n";
        else cout<<"No\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}

