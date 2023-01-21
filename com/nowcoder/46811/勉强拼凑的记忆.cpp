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
typedef __int128 lll;
const int INF=0x3f3f3f3f,mod=1e9+7;
ll n,m,x;
inline bool check(ll x){
    ll nn=n,xx=x;
    nn-=x;
    nn-=x-m;
    if(nn<x-m)return false;
    else return true;
}
void solve(){
    cin>>n;
    if(n==2){cout<<-1<<endl;return;}
    m=n/2+n%2;
    if(n<=1000000000000000)x=floor(sqrt(n*m));
    else {for(x=31622776;(lll)x*(lll)x<=(lll)n*(lll)m;x++);x--;}
    cout<<x*x<<' '<<n*m<<' ';
    if(check(x))cout<<x<<endl;
    else cout<<x-1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}