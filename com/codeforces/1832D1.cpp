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
	int n,m,ans=0;cin>>n>>m;
	VL a(n);
    rep(i,0,n)cin>>a[i];
    sort(all(a));
    while(m--){
        int x;cin>>x;
        VL b=a;
        ll ans=INT_MAX;
        for(int i=x;i>max(0,n-x);i--){
            b[x-i]+=i;
        }
        if(x>n){
            int sub=(x-n)/2+(x-n)%2;
            priority_queue<ll> p;
            rep(i,0,n)p.push(b[i]);
            while(sub--){
                int t=p.top();
                p.pop();
                p.push(t-1);
            }
            while(!p.empty()){
                ans=min(ans,p.top());
                p.pop();
            }
        }else{
            rep(i,0,n)ans=min(ans,b[i]);
        }
        
        
        cout<<ans<<endl;
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}