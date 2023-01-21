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
    ll x,y,X,Y;cin>>x>>y>>X>>Y;
    if(abs(x-X)%2-abs(y-Y)%2!=0){cout<<"No Answer!";return;}
    ll ox=x+X,oy=y+Y;
    ll xx=ox-(Y-y),yy=oy+(X-x);
    cout<<xx/2<<' '<<yy/2;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}