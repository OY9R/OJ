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
void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<int> a(n);
    for(int &i:a)cin>>i;
    priority_queue<int,vector<int>, greater<int>> small(all(a));
    for(int i=0;i<k;i++){
        int t=small.top();
        small.pop();
        small.push(t+m);
    }
    priority_queue<int> big;
    while(small.size()){
        big.push(small.top());
        small.pop();
    }
    ll ans=1;
    for(int i=0;i<k;i++){
        int t=big.top();
        big.pop();
        // while(t<m){
        //     ans=ans*t%mod;
        //     if(!big.size())break;
        //     t=big.top();
        //     big.pop();
        // }
        big.push(t-m);
    }
    while(big.size()){
        ans=ans*big.top()%mod;
        big.pop();
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}