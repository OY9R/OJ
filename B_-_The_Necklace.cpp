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
const int N=55;
int n,p[N],q[N];
inline void init(int n){
    for(int i=1;i<=n;i++)p[i]=i;
    memset(q,0,sizeof q);
}
inline int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
void solve(){
    cin>>n;
    init(50);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        p[find(a)]=find(b);
        q[a]++,q[b]++;
    }
    for(int i=1;i<=50;i++){
        if(q[i]%2){
            cout<<"some beads may be lost\n";
            return;
        }
    }
    set<int> s;
    for(int i=1;i<=50;i++){
        if(q[i])s.insert(find(i));
    }
    if(s.size()>1){
        cout<<"some beads may be lost\n";
        return;
    }
    cout<<"ok\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Case #"<<i<<endl;
        solve();
    }
    return 0;
}