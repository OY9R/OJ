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
    VL a(n);
    rep(i,0,n)cin>>a[i];
    ll sum=0,n1=0;
    rep(i,0,n)sum+=a[i];
    rep(i,0,n)n1+=a[i]==1;
    if(n==1 or sum<n+n1){
        cout<<"NO"<<endl;
        return;
    }else{
        cout<<"YES"<<endl;
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}