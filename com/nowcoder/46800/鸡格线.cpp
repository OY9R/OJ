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
int p[100010];
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
void solve(){
    int n,m;cin>>n>>m;
    VI a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n+1;i++)p[i]=i;
    ll sum=0,flag=0;
    for(int i=1;i<=n;i++)sum+=a[i];
    while(m--){
        int op;cin>>op;
        if(op==1){
            int l,r,k;cin>>l>>r>>k;
            for(int i=find(l);i<=r;i=find(i+1)){
                sum-=a[i];
                for(int j=1;j<=min(15,k);j++){
                    a[i]=round(10*sqrt(a[i]));
                    if(!a[i]||a[i]==100||a[i]==99){
                        p[i]=find(p[i+1]);
                        break;
                    }
                }
                sum+=a[i];
            }
        }else cout<<sum<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}