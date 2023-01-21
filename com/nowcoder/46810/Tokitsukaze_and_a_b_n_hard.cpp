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
const int INF=0x3f3f3f3f;
const int N=200002,mod=998244353;
int M[N];
void solve(){
    int n,m;cin>>n>>m;
    ll sum=0;
    for(int i=0;i<m;i++){
        int l,r;cin>>l>>r;
        M[l]++,M[r+1]--;
        sum+=min(0,(max(l,n-r)-min(r,n-l)-1)/2*2);
    }
    //cout<<sum<<' ';
    for(int i=2;i<N;i++){
        M[i]+=M[i-1];
    }
    for(int i=1;i<n;i++){
        if(i>=N||n-i>=N)continue;
        if(i==n-i)sum+=M[i]*(M[i]-1);
        else sum+=M[i]*M[n-i];
        if(sum>=mod)sum-=mod;
    }
    cout<<sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}