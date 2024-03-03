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
bool check(string s){
    rep(i,0,(int)s.size()-1)
        if(s[i]==s[i+1])return false;
    return true;
}
void solve(){
    int n,m;cin>>n>>m;
    string s,t;cin>>s>>t;
    if(check(s))return cout<<"Yes"<<endl,void();
    if(t.size()%2==0||!check(t))return cout<<"No"<<endl,void();
    rep(i,0,n-1)if(s[i]==s[i+1]&&s[i]==t[0])return cout<<"No"<<endl,void();
    cout<<"Yes"<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}