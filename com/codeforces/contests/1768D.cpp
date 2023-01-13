#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int n,idx=1,ans=0;cin>>n;
    VL a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i],a[i]--;
    for(int i=0;i<n;i++)
        if(!b[i]){
            int v=i;
            while(!b[v])b[v]=idx,v=a[v],ans++;
            idx++,ans--;
        }
    //for(int i=0;i<n;i++)cout<<b[i]<<' ';
    for(int i=0;i<n-1;i++)
        if(b[i]==b[i+1]){
            cout<<ans-1<<endl;
            return;
        }
    cout<<ans+1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}
