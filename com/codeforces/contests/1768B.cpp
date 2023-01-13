#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int n,k;cin>>n>>k;
    VI a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    int cnt=0;
    for(int i=1;i+cnt<=n;i++)
        while(a[i+cnt]>i&&i+cnt<=n)cnt++;
    cout<<cnt/k+(cnt%k>0)<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}