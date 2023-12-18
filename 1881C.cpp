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
	int n,ans=0;cin>>n;
    vector<string> g(n);
    rep(i,0,n)
        cin>>g[i];
    rep(i,0,n/2)
        rep(j,0,n/2){
            int c1,c2,c3,c4;
            c1=g[i][j];
            c2=g[j][n-1-i];
            c3=g[n-1-i][n-1-j];
            c4=g[n-1-j][i];
            // cout<<(char)c1<<(char)c2<<(char)c3<<(char)c4<<endl;
            ans+=max({c1,c2,c3,c4})*4-(c1+c2+c3+c4);
        }
    cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}