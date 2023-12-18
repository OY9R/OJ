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
	int n;string s;cin>>n>>s;
    int cnt0=count(s.begin(),s.end(),'0');
    int cnt1=n-cnt0;
    if(n%2||cnt0!=cnt1)return void(cout<<"-1"<<endl);
    int l=0,r=n-1;
    VI ans;
    while(l<r)
        if(s[l]!=s[r])l++,r--;
        else if(s[l]=='0')
            ans.pb(r+1),
            s.insert(r+1,"01"),
            r+=2;
        else
            ans.pb(l),
            s.insert(l,"01"),
            r+=2;
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i<<' ';
    cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}