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
    int x,y,xp,yp;
    double ans;
    cin>>xp>>yp>>x>>y;
    if(x<=xp&&y<=yp){
        ans=(double)max({x*y,x*(yp-y),(xp-x)*y,(xp-x)*(yp-y)})/(xp*yp);
    }else{
        if(x>xp&&y>yp){
            ans=(double)(xp*yp)/(x*y);
        }else if(x>xp){
            ans=max((double)xp*y/(xp*yp+x*y-xp*y),(double)xp*(yp-y)/(xp*yp+x*(yp-y)-xp*(yp-y)));
        }else{
            ans=max((double)yp*x/(xp*yp+x*y-yp*x),(double)yp*(xp-x)/(xp*yp+y*(xp-x)-yp*(xp-x)));
        }
    }
    printf("%.9lf\n",ans);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}