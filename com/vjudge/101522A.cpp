#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int m;cin>>m;
    vector<int> d(m);
    for(int i=0;i<m;i++)cin>>d[i];
    sort(all(d));
    ll ans=0;
    for(int i=0;i<m-1;i++)
        if(d[i]>i+1)
            if(d[i]<m)ans+=d[i]-i-1;
            else ans+=m-i-1;
    cout<<ans*2;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}