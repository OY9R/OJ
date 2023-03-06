
    // type 1: both Alice and Bob like them;
    // type 2: Alice likes them, but Bob doesn't;
    // type 3: Bob likes them, but Alice doesn't;
    // type 4: neither Alice nor Bob likes them. 

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
    ll a,b,c,d,ans=0;cin>>a>>b>>c>>d;
    if(a==0){
        cout<<(b+c+d>0)<<endl;
        return;
    }
    ll minbc=min(b,c);
    ans+=a+minbc*2;
    b-=minbc,c-=minbc;
    ans+=min(max(b,c),a);
    a-=max(b,c);
    if(a>=0){
        ans+=min(a,d);
        if(a<d)ans++;
    }else if(b+c)ans++;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}