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
const double PI=acos(-1.0);
inline double o(int r){return r*r*PI;}
int n,m,ans=0;
VI a;
bool check(double x){
    int cnt=0;
    for(int i=0;i<n;i++)
        cnt+=(int)(o(a[i])/x);
    return cnt>=m+1;
}
void solve(){
    cin>>n>>m;
    a.resize(n);
    double l=0,r=0;
    for(int i=0;i<n;i++)cin>>a[i],r=max(r,o(a[i]));
    while(r-l>1e-6){
        double mid=(l+r)*0.5;
        if(check(mid)) l=mid;
        else r=mid;
    }
    printf("%.4f\n",r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}