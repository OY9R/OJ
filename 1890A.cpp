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
	VI a(n);
	rep(i,0,n)cin>>a[i];
    map<int,int> m;
    rep(i,0,n)m[a[i]]++;
    if(m.size()>2){
        cout<<"No"<<endl;
        return;
    }
    if(m.size()==1){
        cout<<"Yes"<<endl;
        return;
    }
    VI v;
    for(auto i:m){
        v.pb(i.se);
    }
    if(abs(v[0]-v[1])>1)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}