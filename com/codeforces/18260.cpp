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
int n,a[101];
inline bool check(int m){
    int cnt=0;
    rep(i,0,n)
        if(a[i]>m)cnt++;
    return cnt==m;
}
void solve(){
    cin>>n;
    rep(i,0,n)cin>>a[i];
    rep(i,0,n){
        if(check(i)){
            cout<<i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}