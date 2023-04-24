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
const int N=1e5+10;
int p[N],dis[N],n,m,sum;
int dfs(int x){
    if(p[x]==-1||dis[x]>0) return dis[x];
    sum++;
    dis[x]=dfs(p[x])+1;
    return dis[x];
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>p[i];
    int mx=0,d;
    while(m--){
        cin>>d;
        mx=max(mx,dfs(d));
        cout<<2*sum-mx<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}