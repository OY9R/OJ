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
	ll k;cin>>k;
    ll ans=1;
    if(k>1021){
        ans=9876543210;
        k-=1021;
    }else if(k>1012){
        ans=976543210;
        k-=1012;
    }
    while(--k){
        bool flag=true;
        while(flag){
            ans++;
            ll tmp = ans/10;
            ll low = ans%10;
            flag = false;
            while(tmp){
                if(tmp%10<=low){
                    flag=true;
                    break;
                }
                low=tmp%10;
                tmp/=10;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}