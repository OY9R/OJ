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
    string s,t;cin>>s>>t;
    int dif=0,fid=0;
    rep(i,0,n){
        if(s[i]!=t[i]){
            dif++;
        }
        if(s[i]!=t[n-i-1]){
            fid++;
        }
    }
    // cout<<dif<<' '<<fid<<' ';
    cout<<min(max(0,dif/2*4+dif%2),max(2,(fid+1)/2*4-2+(fid+1)%2))<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}