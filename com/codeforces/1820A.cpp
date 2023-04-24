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
    string s;cin>>s;
    int ans=0;
    bool flag=0;
    if(s[0]=='_')ans=1;
    for(int i=1;i<s.size();i++){
        if(s[i]=='_'&&s[i-1]=='_')ans++;
    }
    if(s[s.size()-1]=='_')ans++;
    if(s.size()==1&&s[0]=='^')ans=1;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}