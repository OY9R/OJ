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
	int n,m;cin>>n>>m;
    VI a(n+1),b(n+1);
    rep(i,1,n+1)cin>>a[i];
    b[1]=1,b[2]=2;
    rep(i,2,n){
        b[i]=b[i-1];
        if(a[i-1]>=a[i]&&a[i]>=a[i+1])b[i]++;
        // cout<<b[i]<<' ';
    }
    while(m--){
        int l,r;cin>>l>>r;
        if(r-l+1<3)cout<<r-l+1<<endl;
        else cout<<r-l+1-b[r-1]+b[l]<<endl;
    }

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}