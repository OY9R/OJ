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
    int n;
    ll a,b;
    string s;
    cin>>n>>a>>b>>s;
    ll minans=LONG_LONG_MAX;
    for(int i=0;i<n;i++){
        ll ans=i*a;
        for(int j=0;j*2<n;j++){
            if(s[(i+j)%n]!=s[(n-j-1+i)%n])ans+=b;
        }
        minans=min(ans,minans);
    }
    cout<<minans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}