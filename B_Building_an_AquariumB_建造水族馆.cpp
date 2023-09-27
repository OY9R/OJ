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
	ll n,x,sum=0,maxh=0;cin>>n>>x;
	VL a(n);
    for(ll &i:a)cin>>i,sum+=i,maxh=max(maxh,i);
    if(n*maxh-sum<=x)return cout<<(x+sum)/n<<endl,void();
    ll l=0,h=INT_MAX;
    while(l<h){
        ll mid=(l+h+1)/2,sum=0;
        for(int i=0;i<n;i++)sum+=max(mid-a[i],0ll);
        if(sum<=x)l=mid;
        else h=mid-1;
    }
    cout<<l<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}