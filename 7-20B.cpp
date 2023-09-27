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
void solve(){
    int n,m,k;cin>>n>>m>>k;
    VI a(m),b(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++){
            int t;cin>>t;
            b[i]|=1<<(t-1);
            a[t-1]++;
        }
    // for(int i=0;i<n;i++)cout<<b[i]<<' ';
    for(int i=0;i<m;i++)
        if(!a[i]){
            cout<<-1<<'\n';
            return;
        }
    queue<PII> q;
    q.push({0,0});
    while(q.size()){
        PII v=q.front();q.pop();
        // cout<<v.fi<<' '<<v.se<<'\n';
        for(int i=0;i<n;i++){
            if((v.se|b[i])==(1<<m)-1){
                cout<<v.fi+1<<'\n';
                return;
            }
            if((v.se|b[i])!=v.se)
                q.push({v.fi+1,v.se|b[i]});
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}