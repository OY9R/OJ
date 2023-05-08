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
int prime[1000001],cnt;
bool vis[1000001];
void init(){
    for(int i=2;i<=1000000;i++){
        if(!vis[i])prime[cnt++]=i;
        for(int j=0;j<cnt&&i*prime[j]<=1000000;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
void solve(){
    int n,m;cin>>n>>m;
    if(n==1){
        cout<<"YES"<<endl;
        return;
    }
    if(n<=m){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;prime[i]<=m&&prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    init();
    int n;cin>>n;
    while(n--)solve();
    return 0;
}