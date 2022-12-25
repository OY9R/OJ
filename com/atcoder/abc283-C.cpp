#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
void solve(){
    string s;cin>>s;
    int ans=s.size();
    for(int i=1;i<s.size();i++)
        if(s[i]=='0'&&s[i-1]=='0')ans--,i++;
    cout<<ans;
}
int main() {
    // int n;cin>>n;
    // while(n--)
        solve();
    return 0;
}