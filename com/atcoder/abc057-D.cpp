#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
ll C(ll n,ll k){
    ll res=1;
    for(int i=1;i<=k;i++)res*=n+1-i,res/=i;
    return res;
}
void solve(){
    int n,a,b;cin>>n>>a>>b;
    vector<double> A(n);
    for(int i=0;i<n;i++)cin>>A[i];
    sort(A.begin(),A.end());
    double sum=0;
    for(int i=0;i<a;i++)sum+=A[n-i-1];
    auto tmp=upper_bound(A.begin(),A.end(),A[n-a]);
    ll ans=0,l=A.end()-tmp,m=tmp-lower_bound(A.begin(),A.end(),A[n-a]);
    if(l!=0)b=a;
    for(int i=a;i<=b;i++)ans+=C(m,i-l);
    printf("%.6f\n%lld",sum/a,ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // int n;cin>>n;
    // while(n--)
        solve();
    return 0;
}