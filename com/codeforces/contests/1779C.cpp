#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int n,m;cin>>n>>m;
    vector<ll> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
        //cout<<b[i]<<' ';
    }
    int cnt=0;
    priority_queue<ll> q;
    ll nbm=b[m];
    for(int i=m-1;i>0;i--){
        if(a[i+1]>0)q.push(a[i+1]);
        while(b[i]<b[m]&&q.size()){
            b[m]-=q.top()*2;
            //cout<<q.top()<<' ';
            cnt++;
            q.pop();
        }
    }
    b[m]=nbm;
    q=priority_queue<ll>();
    for(int i=m+1;i<=n;i++){
        if(a[i]<0)q.push(-a[i]);
        while(b[i]<b[m]&&q.size()){
            b[m]-=q.top()*2;
            //cout<<-q.top()<<' ';
            cnt++;
            q.pop();
        }
    }
    cout<<cnt<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)
        solve();
    return 0;
}