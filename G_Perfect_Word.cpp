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
    vector<string> a(n);
    per(i,0,n)cin>>a[i];
    sort(all(a),[](string x,string y){return x.size()>y.size();});
    // per(i,0,n)cout<<a[i]<<endl;
    unordered_set<string> s;
    int ans=1;
    per(i,0,n){
        if(a[i].size()==1||(s.count(a[i].substr(0,a[i].size()-1))&&s.count(a[i].substr(1)))){
            s.insert(a[i]);
           // cout<<a[i]<<endl;
            ans=max(ans,(int)a[i].size());
        }
    }
    cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}

