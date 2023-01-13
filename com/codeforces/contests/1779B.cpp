#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int n,ans=0;cin>>n;
    if(n==3){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    if(n%2){
        int x=n/2-1,y=-n/2;
        for(int i=0;i<n;i++)
            if(i%2)cout<<y<<' ';
            else cout<<x<<' ';
    }else{
        for(int i=0,j=1;i<n;i++,j=-j)
            cout<<j<<' ';
    }
    cout<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)
        solve();
    return 0;
}