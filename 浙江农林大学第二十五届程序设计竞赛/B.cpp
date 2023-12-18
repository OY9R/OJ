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
const int INF=0x3f3f3f3f,mod=998244353;
int mem[505][505];
int dfs(int n,int x){
    if(n==0)return 0;
    if(~mem[n][x])return mem[n][x];
    int ans=n==x;
    for(int i=1;i<n;i++)
        ans=(ans+dfs(n-i,x^i))%mod;
    return mem[n][x]=ans;
}
void solve(){
    int n;cin>>n;
    memset(mem,-1,sizeof mem);
    if(n&1)return cout<<0,void();
    cout<<dfs(n,0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}