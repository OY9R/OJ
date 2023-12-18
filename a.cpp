#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef vector<int> VI;
typedef vector<long long> VL;
typedef pair<int,int> PII;
typedef long long ll;
const int INF=0x3f3f3f3f,mod=1e9+7;
void solve(){
    int m;cin>>m;
    vector<string> a(3);
    for(int i=0;i<3;i++)
        cin>>a[i],a[i]+=a[i]+a[i];
    vector<int> b(10);
    vector<set<int>> c(10);
    for(int i=0;i<m*3;i++){
        b[a[0][i]-'0']|=1;
        b[a[1][i]-'0']|=2;
        b[a[2][i]-'0']|=4;
        c[a[0][i]-'0'].insert(i);
        c[a[1][i]-'0'].insert(i);
        c[a[2][i]-'0'].insert(i);
        if( b[a[0][i]-'0']==7 && c[a[0][i]-'0'].size()>=3 ||
            b[a[1][i]-'0']==7 && c[a[1][i]-'0'].size()>=3 ||
            b[a[2][i]-'0']==7 && c[a[2][i]-'0'].size()>=3 )
            return cout<<i,void();
        // for(int j=0;j<10;j++)cout<<b[j]<<" ";
        // cout<<endl;
        // for(int j=0;j<10;j++)cout<<c[j].size()<<" ";
        // cout<<endl;
        // cout<<endl;
    }
    cout<<-1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}