#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
void solve(){
    ll n,ans=0;cin>>n;
    vector<ll> a(n+1),b(n+1),c(n+1,1);
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a.begin()+1,a.end());
    reverse(a.begin()+1,a.end());
    for(int i=2;i<=n;i++)cin>>b[i];
    // for(int i=1;i<=n;i++){
    //     int w=i;
    //     while(w!=1){
    //         w=b[w];
    //         c[w]++;
    //     }
    // }
    for(int i=n;i>0;i--){
        if(i!=1)c[b[i]]+=c[i];
    }
    sort(c.begin()+1,c.end());
    reverse(c.begin()+1,c.end());
    for(int i=1;i<=n;i++){
        ans+=a[i]*c[i];
    }
    cout<<ans;
}
int main() {
    // int n;cin>>n;
    // while(n--)
        solve();
    return 0;
}