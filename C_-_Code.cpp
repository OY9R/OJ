#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<list>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<climits>
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
ll c[30][30];
void init(){rep(i,0,27)rep(j,0,i+1)c[i][j]=j?c[i-1][j]+c[i-1][j-1]:1;}
void solve(){
    string s;cin>>s;
    ll ans=0,len=s.size();
    rep(i,1,len)if(s[i-1]>=s[i]){cout<<0<<endl;return;}
    rep(i,1,len)ans+=c[26][i];
    rep(i,'a',s[0])ans+=c['z'-i][len-1];
    rep(i,1,len)rep(j,s[i-1]+1,s[i])ans+=c['z'-j][len-1-i];
    cout<<ans+1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    init();
    solve();
    return 0;
}