#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,n,m,h;
bool check(int x){
    ll lest=m+n-x;
    ll empty=(x/b)*(h-b)+(n/b)*(b-a);
    return lest<=empty;
}
void solve(){
    cin>>a>>b>>n>>m>>h;
    ll l=n+1,r=n+m;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    cout<<l<<endl;
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}