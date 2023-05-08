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
int a1[1005],a2[1005];
void solve(){
    int n;cin>>n;
    cout<<"+ "<<n+1<<endl<<flush;
    int op;cin>>op;
    cout<<"+ "<<n+2<<endl<<flush;
    cin>>op;//至此，排列中的数将构成一条链
    VI a;int na=0;
    a.pb(-1);
    rep(i,1,(n+1)/2+1){
        if(i==n+1-i)a.pb(i);
        else a.pb(i),a.pb(n+1-i);
    }
    int nait;
    rep(i,2,n+1){
        cout<<"? 1 "<<i<<endl<<flush;
        cin>>op;
        if(op>na)na=op,nait=i;
    }
    a1[nait]=a[n];
    a2[nait]=a[1];
    rep(i,1,n+1){
        if(i==nait)continue;
        cout<<"? "<<nait<<' '<<i<<endl<<flush;
        cin>>op;
        a1[i]=a[n-op];
        a2[i]=a[op+1];
    }
    cout<<"! ";
    rep(i,1,n+1)cout<<a1[i]<<' ';
    rep(i,1,n+1)cout<<a2[i]<<' ';
    cout<<endl<<flush;
    cin>>op;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}