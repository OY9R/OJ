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
void solve(){ //1/2(x1y2+x2y3+x3y1-x1y3-x2y1-x3y2)
	double ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
	int abn;cin>>abn;
    vector<double> ab_(abn);
    rep(i,0,abn)cin>>ab_[i];
    int bcn;cin>>bcn;
    vector<double> bc_(bcn);
    rep(i,0,bcn)cin>>bc_[i];
    int can;cin>>can;
    vector<double> ca_(can);
    rep(i,0,can)cin>>ca_[i];
    double abx=bx-ax,aby=by-ay;
    double bcx=cx-bx,bcy=cy-by;
    double cax=ax-cx,cay=ay-cy;
    vector<pair<double,double>> a(2),b(2),c(2);
    double abm=sqrt(abx*abx+aby*aby);
    double bcm=sqrt(bcx*bcx+bcy*bcy);
    double cam=sqrt(cax*cax+cay*cay);
    a[0].fi=abx/abm*ab_[0]+ax,a[0].se=aby/abm*ab_[0]+ay;
    a[1].fi=cax/cam*ca_[can-1]+cx,a[1].se=cay/cam*ca_[can-1]+cy;
    b[0].fi=bcx/bcm*bc_[0]+bx,b[0].se=bcy/bcm*bc_[0]+by;
    b[1].fi=abx/abm*ab_[abn-1]+ax,b[1].se=aby/abm*ab_[abn-1]+ay;
    c[0].fi=cax/cam*ca_[0]+cx,c[0].se=cay/cam*ca_[0]+cy;
    c[1].fi=bcx/bcm*bc_[bcn-1]+bx,c[1].se=bcy/bcm*bc_[bcn-1]+by;
    // cout<<a[0].fi<<' '<<a[0].se<<endl;
    // cout<<a[1].fi<<' '<<a[1].se<<endl;
    // cout<<b[0].fi<<' '<<b[0].se<<endl;
    // cout<<b[1].fi<<' '<<b[1].se<<endl;
    // cout<<c[0].fi<<' '<<c[0].se<<endl;
    // cout<<c[1].fi<<' '<<c[1].se<<endl;
    double S=0;
    for(int i=0;i<8;i++){//1/2(x1y2+x2y3+x3y1-x1y3-x2y1-x3y2)
        S=max(S,a[i&1].fi*b[i>>1&1].se+b[i>>1&1].fi*c[i>>2&1].se+c[i>>2&1].fi*a[i&1].se-a[i&1].fi*c[i>>2&1].se-b[i>>1&1].fi*a[i&1].se-c[i>>2&1].fi*b[i>>1&1].se);
        //cout<<i<<' '<<a[i&1].fi*b[i>>1&1].se+b[i>>1&1].fi*c[i>>2&1].se+c[i>>2&1].fi*a[i&1].se-a[i&1].fi*c[i>>2&1].se-b[i>>1&1].fi*a[i&1].se-c[i>>2&1].fi*b[i>>1&1].se<<endl;
        //cout<<a[i&1].fi<<'*'<<b[i>>1&1].se<<'+'<<b[i>>1&1].fi<<'*'<<c[i>>2&1].se<<'+'<<c[i>>2&1].fi<<'*'<<a[i&1].se<<'-'<<a[i&1].fi<<'*'<<c[i>>2&1].se<<'-'<<b[i>>1&1].fi<<'*'<<a[i&1].se<<'-'<<c[i>>2&1].fi<<'*'<<b[i>>1&1].se<<endl;
    }
    printf("%.7lf",S/2);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}