#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int lr=-1,rl=-1;
    for(int i=0;i<n;i++)
        if(s[i]=='R'){
            lr=i;break;
        }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='L'){
            rl=i;break;
        }
    }
    if(lr==-1||rl==-1){
        cout<<"-1\n";
        return;
    }
    if(lr<rl){
        cout<<"0\n";
        return;
    }
    if(lr>rl+1){
        cout<<"-1\n";
        return;
    }
    cout<<rl+1<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)
        solve();
    return 0;
}