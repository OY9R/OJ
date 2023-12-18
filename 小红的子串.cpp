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
	int n,l,r,ans=0;cin>>n>>l>>r;
    string s;cin>>s;
    vector<pair<int,int>> ss;
    int cnt=1;
    for(int i=0;i<n;i++){
        if(i+1==n||s[i]!=s[i+1])
            ss.pb(mp(s[i]-'a',cnt)),cnt=1;
        else cnt++;
    }
    n = ss.size();
    // for(auto i : ss){
    //     cout<<i.fi<<" "<<i.se<<endl;
    // }
    if(l==1){
        // todo
        l++;
    }
    for(int i=l;i<=r;i++){
        cnt=1;
        // cout<<i<<':'<<endl;
        vector<int> vis(26);
        vis[ss[0].fi]=1;
        for(int l=0,r=0;l<=r&&r<n;){
            if(cnt==i){
                // cout<<l<<'-'<<r<<' '<<ss[l].se<<'*'<<ss[r].se<<endl;
                ans+=ss[l].se*ss[r].se;
                vis[ss[l].fi]--;
                if(vis[ss[l].fi]==0)cnt--;
                l++;
                // r++;
                // vis[ss[r].fi]++;
                // if(vis[ss[r].fi]==1)cnt++;
            }
            while(r<n&&cnt<i){
                r++;vis[ss[r].fi]++;
                if(vis[ss[r].fi]==1)cnt++;
            }
            while(l<r&&cnt>i){
                vis[ss[l].fi]--;
                if(vis[ss[l].fi]==0)cnt--;
                l++;
            }
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