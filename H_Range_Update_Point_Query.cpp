#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define lowbit(x) ((x)&(-x))
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
	int n,q;cin>>n>>q;
	VI a(n+1),b(n+2);rep(i,1,n+1)cin>>a[i];
    while(q--){
        int f;cin>>f;
        if(f==1){
            int l,r;cin>>l>>r;r++;
            while(l<=n)b[l]++,l+=lowbit(l);
            while(r<=n)b[r]--,r+=lowbit(r);
        }else{
            int i;cin>>i;
            int x=i,t=0;
            while(x)t+=b[x],x-=lowbit(x);
            x=a[i];
            // cout<<x<<' '<<t<<' ';
            while(t--){
                if(x<10)break;
                int tmp=0;
                while(x)tmp+=x%10,x/=10;
                x=tmp;
            }
            cout<<x<<endl;
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}