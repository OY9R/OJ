#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int n,m,ans=0;cin>>n>>m;
    vector<ll> a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    priority_queue<int,vector<int>,greater<int> >q;
    ll sum=0;
    for(int i=0;i<n;i++){
        q.push(a[i]);
    }
    for(int i=0;i<m;i++){
        q.pop();
        q.push(b[i]);
    }
    while(q.size()){
        sum+=q.top();
        q.pop();
    }
    cout<<sum<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)
        solve();
    return 0;
}