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
    int n,mx=0;cin>>n;
    vector<int> a(n),b,c;
    for(int i=0;i<n;i++){
        int m;cin>>m;
        for(int j=0;j<b.size();j++){
            if(m==b[j]+(c[j]%2*2-1)*(c[j]+1)/2){
                mx=max(++c[j],mx);
            }
        }
        if(n-i>mx*mx*mod){
            b.push_back(m);
            c.push_back(1);
        }
    }
    for(int i=0;i<n;i++){
        // cout<<b[i]<<':'<<c[i]<<endl;
    }
    cout<<mx;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}