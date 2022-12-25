#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
void solve(){
    int n;cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int q;cin>>q;
    while(q--){
        int o,x,y;
        cin>>o;
        if(o==1)cin>>x>>y,a[x-1]=y;
        else cin>>x,cout<<a[x-1]<<endl;
    }
}
int main() {
        solve();
    return 0;
}