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
    map<int,int> mm;
    int n;cin>>n;
    //vector<stack<int>> g(n,stack<int>());
    for(int i=1;i<=n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int k;cin>>k;
            if(mm.count(k))mm[k]=0;
            else mm[k]=i;
        }
    }
    vector<bool> a(n);
    for(PII i: mm){
        a[i.second]=true;
    }
    for(int i=1;i<=n;i++){
        if(!a[i]){cout<<"Yes\n";return;}
    }
    cout<<"No\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}