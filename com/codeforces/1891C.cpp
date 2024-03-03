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
    sort(all(a));
    ll cnt=0,combo=0;
    for(int i=0,j=n-1;i<=j;i++){
        cnt+=a[i],combo+=a[i];
        if(i<j&&combo>=a[j])
            combo-=a[j],cnt++,j--;
    }
    if(combo>1){
        combo-=combo&1;
        cnt-=combo/2;
        cnt++;
    }
    cout<<cnt<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}