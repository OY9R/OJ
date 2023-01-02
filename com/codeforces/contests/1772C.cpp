#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
void solve(){
    int k,n;cin>>k>>n;
    int ans=1;
    for(int i=0;i<k;i++){
        ans+=i;
        if(ans>n-(k-i-1))ans=n-(k-i-1);
        cout<<ans<<' ';
    }
    cout<<endl;
}
int main() {
    int n;cin>>n;
    while(n--)
        solve();
    return 0;
}