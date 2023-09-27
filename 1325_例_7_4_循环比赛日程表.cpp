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
    ll m=1l<<n;
    vector<VI> a(m,VI(m));
    rep(i,0,m)a[0][i]=i+1;
    for(ll i=1;i<m;i<<=1)
        for(ll j=0;j<m;j+=i*2)
            for(ll k=0;k<i;k++)
                for(ll l=0;l<i;l++)
                    a[i+k][i+j+l]=a[k][j+l],
                    a[i+k][j+l]=a[k][i+j+l];
    rep(i,0,m){
        rep(j,0,m)cout<<a[i][j]<<' ';
        cout<<endl;
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}