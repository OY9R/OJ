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
int n;
ll aa[200005],bb[200005];
bool check(ll x,ll y){
    multiset<PII> a,b;
    for(int i=1;i<=n;i++){
        a.insert({aa[i],bb[i]});
        b.insert({bb[i],aa[i]});
    }
    for(int i=1;i<=n;i++){
        int tx=a.rbegin()->fi,ty=a.rbegin()->se;
        if(tx==x){
            a.erase(a.find({tx,ty}));
            b.erase(b.find({ty,tx}));
            y-=ty;
            continue;
        }
        tx=b.rbegin()->se,ty=b.rbegin()->fi;
        if(ty==y){
            a.erase(a.find({tx,ty}));
            b.erase(b.find({ty,tx}));
            x-=tx;
            continue;
        }
        return false;
    }
    return true;
}
void solve(){
    cin>>n;
    ll mx=0,my=0;
    ll s=0;
    for(int i=1;i<=n;i++){
        ll x,y;cin>>x>>y;
        aa[i]=x,bb[i]=y;
        mx=max(mx,x),my=max(my,y);
        s+=(ll)x*y;
    }
    vector<pair<ll,ll>> ans;
    if(s%mx==0&&check(mx,s/mx))ans.push_back({mx,s/mx});
    if(s%my==0&&check(s/my,my))ans.push_back({s/my,my});
    if(ans.size()==2&&ans[0]==ans[1])ans.pop_back();
    cout<<ans.size()<<endl;
    for(auto ti:ans)cout<<ti.fi<<' '<<ti.se<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int _;cin>>_;
    while(_--)solve();
    return 0;
}