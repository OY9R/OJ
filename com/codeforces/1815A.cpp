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
    VI a(n+1);rep(i,1,n+1)cin>>a[i];
    if(n%2){cout<<"Yes"<<endl;return;}
    ll sum=0;
    rep(i,1,n+1){
        if(i%2==0)sum+=a[i];
        else sum-=a[i];
    }
    if(sum>=0){cout<<"Yes"<<endl;return;}
    cout<<"No"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}