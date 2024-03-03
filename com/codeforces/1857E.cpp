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
	int n;cin>>n;
    vector<PII> a(n);
    rep(i,0,n)cin>>a[i].fi,a[i].se=i;
    sort(all(a));
    ll l=0,r=0;
    rep(i,1,n)r+=a[i].fi-a[0].fi+1;
    VL b(n);
    rep(i,0,n){
        if(i>0)l+=((ll)a[i].fi-a[i-1].fi)*i+1;
        if(i>0)r-=((ll)a[i].fi-a[i-1].fi)*(n-i)+1;
        // cout<<l<<":"<<r<<" ";
        b[a[i].se]=l+r+1;
    }
    // cout<<endl;
    rep(i,0,n)cout<<b[i]<<" ";
    cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}