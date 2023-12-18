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
	VI a(10),p(10);
	rep(i,1,10)cin>>a[i],p[i]=i;
    // 1 2 3
    // 4 5 6
    // 7 8 9
    ll all=0,lost=0;
    while(true){
        all++;
        if(
            a[1]==a[2]&&p[1]<p[3]&&p[2]<p[3]||a[1]==a[3]&&p[1]<p[2]&&p[3]<p[2]||a[2]==a[3]&&p[2]<p[1]&&p[3]<p[1]||
            a[4]==a[5]&&p[4]<p[6]&&p[5]<p[6]||a[4]==a[6]&&p[4]<p[5]&&p[6]<p[5]||a[5]==a[6]&&p[5]<p[4]&&p[6]<p[4]||
            a[7]==a[8]&&p[7]<p[9]&&p[8]<p[9]||a[7]==a[9]&&p[7]<p[8]&&p[9]<p[8]||a[8]==a[9]&&p[8]<p[7]&&p[9]<p[7]||
            a[1]==a[4]&&p[1]<p[7]&&p[4]<p[7]||a[1]==a[7]&&p[1]<p[4]&&p[7]<p[4]||a[4]==a[7]&&p[4]<p[1]&&p[7]<p[1]||
            a[2]==a[5]&&p[2]<p[8]&&p[5]<p[8]||a[2]==a[8]&&p[2]<p[5]&&p[8]<p[5]||a[5]==a[8]&&p[5]<p[2]&&p[8]<p[2]||
            a[3]==a[6]&&p[3]<p[9]&&p[6]<p[9]||a[3]==a[9]&&p[3]<p[6]&&p[9]<p[6]||a[6]==a[9]&&p[6]<p[3]&&p[9]<p[3]||
            a[1]==a[5]&&p[1]<p[9]&&p[5]<p[9]||a[1]==a[9]&&p[1]<p[5]&&p[9]<p[5]||a[5]==a[9]&&p[5]<p[1]&&p[9]<p[1]||
            a[3]==a[5]&&p[3]<p[7]&&p[5]<p[7]||a[3]==a[7]&&p[3]<p[5]&&p[7]<p[5]||a[5]==a[7]&&p[5]<p[3]&&p[7]<p[3]
        )lost++;
        if(!next_permutation(p.begin()+1,p.end()))break;
    }
    // printf("%lld %lld\n",all,lost);
    printf("%.10lf",(double)(all-lost)/all);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}