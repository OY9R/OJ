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
int find(int x,VI &p){
    if(p[x]!=x)p[x]=find(p[x],p);
    return p[x];
}
void solve(){
    int n,m;cin>>n>>m;
    VI p(n+1);
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        p[find(x,p)]=find(y,p);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(p[i]==i)cnt++;
    }
    cout<<max(0,m-n+cnt);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}