#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
void solve(){
    int n,k,a,b;cin>>n>>k>>a>>b;
    int e=(k+n-2)*b,f=(n-1)*a;
    if(e<f)cout<<1;
    else if(e>f)cout<<2;
    else cout<<0;
}
int main() {
    // int n;cin>>n;
    // while(n--)
        solve();
    return 0;
}