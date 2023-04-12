#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
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
const int N=1000;
ll f(ll n,ll m){
    if(n*m==0)return 1;
    m=min(n-m,m);
    ll b=1,s=n-m+1,r=1,c=1;
    while(c<=m){
        ll g=__gcd(s,b);
        r=r*(s/g)/(b/g);
        s++,b++,c++;
    }
    return r;
}
void solve(){
    for(int n,m;cin>>n>>m&&n+m;){
        cout<<f(n,m)<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}