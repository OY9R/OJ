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
	ll a,k,q;cin>>a>>k>>q;
    while(q--){
        ll l,r;cin>>l>>r;
        // cout<<l<<' '<<r<<endl;
        if(k%2==0){
            cout<<(a%2?1:-1)<<endl;
        }else{
            if((r-l)%2){
                cout<<0<<endl;
            }else{
                if((a+k*(l-1))&1)cout<<1<<endl;
                else cout<<-1<<endl;
            }
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	solve();
	return 0;
}