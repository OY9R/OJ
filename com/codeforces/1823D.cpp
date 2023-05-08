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
    int n,k;cin>>n>>k;
    VI a(n+1);rep(i,1,k+1)cin>>a[i];
    VI b(n+1);rep(i,1,k+1)cin>>b[i];
    int cnt=3,ni=3,ci=1,j=0;
    string out="abc";
    rep(i,1,k+1){
        while(cnt<b[i])cnt++,ni++;
        for(;ni<a[i];ni++,j++);
        if(cnt!=b[i]||ni!=a[i]){cout<<"NO"<<endl;return;}
    }
    cnt=3,ni=3,ci=1,j=0;
    cout<<"YES\nabc";
    rep(i,1,k+1){
        while(cnt<b[i])cout<<char('c'+i),cnt++,ni++;
        for(;ni<a[i];ni++,j++)cout<<char('a'+j%3);
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}