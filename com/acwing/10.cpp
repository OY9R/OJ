#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
const int N=110,M=110;
int n,m,h[N],e[N],ne[N],idx,w[N],v[N],f[N][M];
void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx++;}
void dfs(int u){
    for(int i=h[u];~i;i=ne[i]){
        int to
    }
}
void solve(){
    int n,m,ans=0;cin>>n>>m;
    vector<ll> a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}