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
	int n;cin>>n;
    VI a;
    int befor=0;
    rep(i,1,n){
        cout<<"? "<<i<<" "<<i+1<<endl;
        cout.flush();
        int x;cin>>x;
        if(befor!=x&&x==0){
            a.pb(i);
        }
        befor=x;
    }
    if(befor==0)a.pb(n);
    rep(i,0,a.size())cout<<a[i]<<" ";
    cout<<endl;
    // rep(i,0,a.size()-1){
    //     cout<<"? "<<a[i]<<" "<<a[i+1]<<endl;
    //     cout.fflush();
    //     int x;cin>>x;
    //     if(x>=(a[i+1]-a[i])){
    //         // cout<<"! "<<a[i]+1<<endl;
    //         // cout.fflush();
    //         // return;
    //     }
    // }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}