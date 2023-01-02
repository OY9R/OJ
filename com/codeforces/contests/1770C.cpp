#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int n,ans=0;cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int odd=0,even=0;
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            cout<<"NO\n";
            return;
        }
    }
    for(int i=2;i*2<=n;i++){
        vector<ll> b(i,0);
        for(int j=0;j<n;j++){
            b[a[j]%i]++;
        }
        int j=0;
        for(;j<i;j++){
            if(b[j]<2)break;
        }
        if(j==i){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)
        solve();
    return 0;
}