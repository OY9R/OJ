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
    int n,m;cin>>n>>m;
    if(m%2){
        int t=0,a=n/2*m,b=0;
        rep(i,0,n){
            if(i%2==0){
                rep(j,1,m+1)cout<<j+a<<' ';
                a+=m;
            }else{
                rep(j,1,m+1)cout<<j+b<<' ';
                b+=m;
            }
            cout<<endl;
        }
    }else{
        rep(i,0,n){
            rep(j,1,m+1){
                cout<<i*m+j<<' ';
            }
            cout<<endl;
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