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
	ll n,c,cc;cin>>n>>c>>cc;
    if(cc>c+c){
        cout<<n*3*c<<endl;
        return;
    }
    if(cc<c){
        c=cc;
    }
    ll ans=0;
    per(i,0,n){
        string s;cin>>s;
        if(s[0]==s[1]||s[1]==s[2]||s[0]==s[2])ans+=cc+c;
        else ans+=c+c+c;
    }
    cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}