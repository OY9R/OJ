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
int m[100001];
void solve(){
    memset(m,0,sizeof m);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        m[a]++;
    }
    VI nn(n+1);
    ll cnt=0;
    for(int i=1;i<=100000;i++){
        if(m[i]){
            nn[m[i]]++;
            cnt++;
        }
    }
    ll sum=nn[1];cnt-=nn[1];
    cout<<sum<<endl;
    for(int i=2;i<=n;i++){
        sum+=nn[i]+cnt;
        cout<<sum<<endl;
        cnt-=nn[i];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}