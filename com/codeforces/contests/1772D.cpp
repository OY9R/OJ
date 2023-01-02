#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
void solve(){
    int n;cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int l=0,r=INT_MAX>>1;
    for(int i=1;i<n;i++){
        if(a[i-1]<a[i])r=min(r,(a[i-1]+a[i])/2);
        if(a[i-1]>a[i])l=max(l,(a[i-1]+a[i])/2+(a[i-1]+a[i])%2);
    }
    if(l<=r)cout<<(l+r)/2;
    else cout<<-1;
    cout<<endl;
}
int main() {
    int n;cin>>n;
    while(n--)
        solve();
    return 0;
}