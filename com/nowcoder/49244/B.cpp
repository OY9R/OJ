#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
void solve(){
    int n,m,ans=0;cin>>n>>m;
    vector<vector<char>> g(n,vector<char>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)cin>>g[i][j];
    int maxs=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j]=='#')
                maxs=max({maxs,i+j,(n-i-1)+j,i+(m-j-1),(n-i-1)+(m-j-1)});
    cout<<maxs;
}
int main() {
    // int n;cin>>n;
    // while(n--)
        solve();
    return 0;
}