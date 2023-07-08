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
    VI a(n);rep(i,0,n)cin>>a[i];
    VI b(n);rep(i,0,n)cin>>b[i];
    VI c(2*n+1),d(2*n+1);
    int m=1;
    rep(i,1,n){
        if(a[i]==a[i-1])m++;
        else{
            c[a[i-1]]=max(c[a[i-1]],m);
            m=1;
        }
    }
    c[a[n-1]]=max(c[a[n-1]],m);
    m=1;
    rep(i,1,n){
        if(b[i]==b[i-1])m++;
        else{
            d[b[i-1]]=max(d[b[i-1]],m);
            m=1;
        }
    }
    d[b[n-1]]=max(d[b[n-1]],m);
    m=1;
    rep(i,1,2*n+1){
        // cout<<c[i]<<' '<<d[i]<<endl;
        m=max(m,c[i]+d[i]);
    }
    cout<<m<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}