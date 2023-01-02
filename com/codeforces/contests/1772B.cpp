#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>b&&c>d||a<b&&c<d)
        if(a>c&&b>d||a<c&&b<d)
            cout<<"YES";
        else cout<<"NO";
    else cout<<"NO";
    cout<<endl;
}
int main() {
    int n;cin>>n;
    while(n--)
        solve();
    return 0;
}