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
int solve(){
	ll n,k;cin>>n>>k;
    if(k==n+1)return cout<<0<<endl,0;
    if(k<n+1||(k-n-1)%2)return cout<<-1<<endl,0;
    if(k-n-1>(n-1)/4*4)return cout<<-1<<endl,0;
	cout<<(k-n-1)/4*4+(k-n-1)%4/2*3<<endl;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}