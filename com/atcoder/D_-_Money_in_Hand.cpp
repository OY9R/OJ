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
int n,x;
vector<PII> a;
bool dp[51][10001];
void dfs(int i,int x){
    if(dp[i][x]){return;}
    dp[i][x]=true;
    if(x==0){cout<<"Yes";exit(0);}
    if(i==n){return;}
    for(int j=min(x/a[i].fi,a[i].second);~j;j--){
        int xx=x-a[i].fi*j;
        if(xx==0){cout<<"Yes";exit(0);}
        dfs(i+1,xx);
    }
}
void solve(){
    cin>>n>>x;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i].fi>>a[i].se;
    }
    sort(all(a));
    reverse(all(a));
    dfs(0,x);
    cout<<"No";return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}