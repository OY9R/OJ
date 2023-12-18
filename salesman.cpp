#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define fi first
#define se second
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
void solve(){
    int n;cin>>n;
    vector<PII> a(n);
    rep(i,0,n)cin>>a[i].fi;
    rep(i,0,n)cin>>a[i].se;
    sort(all(a),[](PII a,PII b){return a.se>b.se;});
    vector<int> ms(n),sa(n),as(n+1);
    ms[0]=a[0].fi,sa[0]=a[0].se;
    rep(i,1,n)ms[i]=max(ms[i-1],a[i].fi),sa[i]=sa[i-1]+a[i].se;
    per(i,0,n)as[i]=max(as[i+1],a[i].fi*2+a[i].se);
    rep(i,0,n)cout<<max(ms[i]*2+sa[i],i?as[i]+sa[i-1]:as[i])<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}