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
int n,i;
vector<int> d,s;
vector<pair<int,int>> tree;
void solve(){
    cin>>n;
    d.resize(n),s.resize(n);
    for(int &i:d)cin>>i;
    for(int &i:s)cin>>i;
    for(int i=0;i<n;i++){
        if(s[d[i]-1]==1)continue;
        for(int j=i+1;j-i<s[d[i]-1];j+=s[d[j]-1]){
            // cout<<i<<' '<<j<<endl;
            tree.push_back({min(d[i],d[j]),max(d[i],d[j])});
        }
    }
    // cout<<endl;
    sort(all(tree));
    for(auto i:tree){
        cout<<i.first<<' '<<i.second<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}