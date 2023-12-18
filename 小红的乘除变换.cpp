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
	ll x,y;cin>>x>>y;
    ll x5=0,x6=0,y5=0,y6=0;
    while(x%5==0)x5++,x/=5;
    while(y%5==0)y5++,y/=5;
    while(x%6==0)x6++,x/=6;
    while(y%6==0)y6++,y/=6;
    if(x==y&&x5<=y5&&x6>=y6)
        cout<<y5-x5+x6-y6<<endl;
    else 
        cout<<-1<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}