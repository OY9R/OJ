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
int dfs(int x)
void solve(){
    int n;cin>>n;
    vector<int> a(x+1),b(x+1),c(x+1);
    int ans= 0;
    int cnt = 0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        b[a[i]]++;
    for(int i=1;i<=n;i++)
        c[a[i]] += b[i] > 0;
    for(int i= 1; i < n; i ++)
        if(b[i] == 0) cnt ++;
    if(cnt == 1){
        cout << 1 << endl;
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}