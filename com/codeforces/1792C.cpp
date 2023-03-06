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
    rep(i,1,n+1){
        int t;cin>>t;
        a[t]=i;
    }
    ll ans1=0,ans2=0,ans3=0;
    for(int i=n/2;i>0;i--){
        if(a[i]>a[n-i+1]){
            ans1=i;
            break;
        }
    }
    for(int i=n/2;i>0;i--){
        if(a[i]>a[n-i+1]){
            swap(a[i],a[n-i+1]);
        }
    }
    int o=n%2==0;
    for(int i=n/2-o;i>0;i--){
        if(a[i]>a[i+1]){
            ans2=i;
            break;
        }
    }
    for(int i=n/2-o;i>0;i--){
        //cout<<n-i+1<<':'<<n-i<<endl;
        if(a[n-i+1]<a[n-i]){
            ans3=i;
            break;
        }
    }
    //cout<<ans1<<' '<<ans2<<' '<<ans3<<endl;
    cout<<max({ans1,ans2,ans3})<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}