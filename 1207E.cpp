#include<bits/stdc++.h>
using namespace std;
// #define endl '\n'
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
	vector<ll> a(100),b(100);
    ll A,B;
    for(int i=0;i<100;i++)a[i]=i,b[i]=(i+1)<<7;
    cout<<'?';
    for(int i=0;i<100;i++)cout<<' '<<a[i];
    cout<<endl;
    cout.flush();
    cin>>A;
    cout<<'?';
    for(int i=0;i<100;i++)cout<<' '<<b[i];
    cout<<endl;
    cout.flush();
    cin>>B;
    // ll x = 0;
    // x |= (A & (((1 << 7) - 1) << 7));
    // x |= (B & ((1 << 7) - 1));
    // cout<<(A>>7<<7)<<' '<<(B&((1<<7)-1))<<endl;
    cout<<"! "<<((A>>7<<7)|(B&((1<<7)-1)))<<endl;
}
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	solve();
	return 0;
}