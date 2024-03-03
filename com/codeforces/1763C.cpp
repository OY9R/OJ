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
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    if(n>3){
        cout<<n**max_element(all(a))<<endl;
    }else if(n==2){
        cout<<max(a[0]+a[1],2*abs(a[0]-a[1]))<<endl;
    }else if(n==3){
        cout<<max({abs(a[0]-a[1])*3,abs(a[2]-a[1])*3,a[0]*3,a[2]*3,a[0]+a[1]+a[2]})<<endl;
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}