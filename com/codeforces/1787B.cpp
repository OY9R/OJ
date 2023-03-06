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
    ll n;cin>>n;
    ll ans=0,x=n,tmp=1;
    vector<PII> a;
    for(ll i=2;i*i<=x;i+=2){
        if(x%i==0){
            tmp*=i;
            int cnt=0;
            for(;x%i==0;x/=i)cnt++;
            a.pb({cnt,i});
        }
        if(i==2)i--;
    }
    if(x!=1)a.pb({1,x}),tmp*=x;
    sort(all(a));
    //cout<<tmp<<' ';
    int level=0;
    for(int i=0;i<a.size();i++){
        //cout<<a[i].se<<':'<<a[i].fi<<' ';
        ans+=(a[i].fi-level)*tmp;
        level=a[i].fi;
        tmp/=a[i].se;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}