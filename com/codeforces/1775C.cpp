#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    ll n,x;cin>>n>>x;
    if((n&x)!=x){cout<<"-1\n";return;}
    ll m=n;
    while((n&x)==x&&n!=x)
        m+=m&-m,n&=m;
    if(n==x)cout<<m<<endl;
    else cout<<"-1\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}