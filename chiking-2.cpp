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
int g[1001][1001];
void solve(){
    int n,m,ans=0;cin>>n>>m;
    rep(i,0,n)rep(j,0,m)cin>>g[i][j];
    for(int i=n%3==0;i<n;i+=3){
        for(int j=m%3==0;j<m;j+=3){
            ans+=g[i][j];
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}