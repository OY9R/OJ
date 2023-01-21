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
VL tree,ball,deep;
int dfs(int i){
    if(deep[i])return deep[i];
    deep[i]=dfs(tree[i])+1;
    return deep[i];
}
void solve(){
    int n;cin>>n;
    deep.resize(n+1);
    tree.resize(n+1);
    ball.resize(n+1);
    for(int i=2;i<=n;i++)cin>>tree[i];
    for(int i=1;i<=n;i++)cin>>ball[i];
    deep[1]=1;
    for(int i=2;i<=n;i++){
        dfs(i);
    }
    // for(int i=1;i<=n;i++)
    //     cout<<deep[i]<<' ';
    sort(all(ball));
    sort(all(deep));
    ll sum=0;
    for(int i=1;i<=n;i++)
        sum+=ball[i]*deep[i];
    cout<<sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}