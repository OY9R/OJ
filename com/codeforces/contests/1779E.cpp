#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int n,ans=0;cin>>n;
    for(int i=1;i<=n;i++){
        string s(n,'1');
        s[i-1]='0';
        cout<<"? "<<i<<' '<<s<<endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // int n;cin>>n;
    // while(n--)
        solve();
    return 0;
}