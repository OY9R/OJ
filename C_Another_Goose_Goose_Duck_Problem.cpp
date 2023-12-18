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
const int N = 1e5+9;
bool isprime(int x){
    if(x < 2) return 0;
    for(int i = 2; i <= sqrt(x); i++){
        if(x%i==0) return 0;
    }
    return 1;
}
void solve(){
    int a[N];
	ll n;cin>> n;
    int ans = 0;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    int ans= a[0];
    for(int i= 0; i < n; i ++){
        if(a[i]%ans!=0) ans = a[0] / 2;
    }
    
    cout << ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}