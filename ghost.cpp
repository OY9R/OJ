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
    int n;cin>>n;
    if(n==2){
        string s;cin>>s;
        vector<deque<char>> a(n);
        for(int i=0;i<s.size();i++)
            a[i%n].push_back(s[i]);
        for(int i=0;i<10000000;i++){
            int nx=(i+1)%n;
            char nc=a[nx].front();a[nx].pop_front();
            while(a[nx].size()&&a[nx].front()==' ')a[nx].pop_front();
            if(!a[nx].size()){cout<<nx+1;return;}
            for(int j=0;j<a[i%n].size();j++){
                if(a[i%n][j]==nc)a[i%n][j]=' ',nc=' ';
                // cout<<a[i%n][j];
            }
            if(nc!=' ')a[i%n].push_back(nc);
            // cout<<n<<' '<<nc<<'\n';
        }
    }else
    cout<<-1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}