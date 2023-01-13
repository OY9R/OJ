#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    ll n;cin>>n;
    for(ll i=sqrt(n);i>=1;i--){
        if(n%i==0){
            int ans=n/i,cnt=0;
            while(ans){
                cnt++;
                ans/=10;
            }
            cout<<cnt;
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // int n;cin>>n;
    // while(n--)
        solve();
    return 0;
}