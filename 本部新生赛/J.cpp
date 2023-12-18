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
const int N=1001;
int p[N];
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
void solve(){
    int n,m,q;cin>>n>>m>>q;
    for(int i=1;i<=n;i++)p[i]=i;
    while(m--){
        for(int j=1;j<=n;j++){
            int t;cin>>t;
            if(t!=j)p[find(t)]=find(j);
        }
    }
    while(q--){
        int a,b;cin>>a>>b;
        if(find(a)==find(b))cout<<"yes\n";
        else cout<<"no\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}