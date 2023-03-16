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
    int n;cin>>n;
    VI a(n+1);
    for(int i=1;i<=n;i++)a[i]=i;
    for(int i=1;i<n;i++)swap(a[i],a[i+rand()%(n-i+1)]);
    
    while(true){
        int ans=0;
        for(int i=1;i<=n;i++){
            int t;cin>>t;
            if(t==a[i])ans++;
        }
        cout<<ans<<endl;
        if(ans==n)break;
    }
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    srand(time(0));
    solve();
    return 0;
}