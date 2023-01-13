#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve1(){
    int n;cin>>n;
    VI a(n);
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans^=a[i];
    }
    for(int i=0;i<n;i++)cout<<(ans^a[i])<<' ';
}
void solve(){
    string a,b;cin>>a>>b;
    int ans=0;
    for(int i=0;i<a.size();i++)
        ans+=(int)(a[i]!=b[i]);
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}