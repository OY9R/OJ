#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
void solve(){
    int n,k;cin>>n>>k;
    vector<vector<int>> g(k+1,vector<int>(n+1));
    long long t=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<min(i+1,k);j++){
            g[(j+t)%k][i]=(i+1-j)/k+((i+1-j)%k!=0);
        }
        t+=i+1;
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++)
            cout<<g[i][j]<<' ';
        cout<<endl;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int n;cin>>n;
    // while(n--)
        solve();
    return 0;
}