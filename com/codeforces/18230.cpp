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
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        if(i*(i-1)/2+(n-i)*(n-i-1)/2==m){
            cout<<"YES"<<endl;
            rep(j,0,i)cout<<1<<" ";
            rep(j,0,n-i)cout<<-1<<" ";
            cout<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}