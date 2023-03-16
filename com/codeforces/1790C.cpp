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
VI b;
void solve(){
    int n;cin>>n;
    VI a(n+1);
    b.resize(n+1);
    for(int i=0;i<=n;i++)b[i]=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            int a;cin>>a;
            b[a]+=j;
        }
    }
    for(int i=1;i<=n;i++)a[i]=i;
    sort(a.begin()+1,a.end(),[](int x,int y){return b[x]<b[y];});
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}