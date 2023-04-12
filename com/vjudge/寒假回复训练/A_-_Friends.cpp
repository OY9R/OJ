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
const int N=114514;
int p[N];
inline void init(int n){
    for(int i=1;i<=n;i++)p[i]=i;
}
inline int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
void solve(){
    int n,m,ans=0;cin>>n>>m;
    init(n);
    while(m--){
        int a,b;cin>>a>>b;
        p[find(a)]=find(b);
    }
    VI c(n+1);
    for(int i=1;i<=n;i++){
        c[find(i)]++;
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,c[i]);
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}