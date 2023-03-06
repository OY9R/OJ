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
    vector<int> a(n);
    for(int &i:a)cin>>i;
    for(int i=0;i<n;i++){
        // cout<<i<<':';
        for(int j=1;i+j<n;j++){
            // cout<<a[i]+(j+1)/2*(j%2*2-1)<<' ';
            if(a[j+i]==a[i]+(j+1)/2*(j%2*2-1))
                mx=max(mx,j);
            else{
                i=max(i,i+j-2);
                break;
            }
        }
        if(mx==n-1)break;
        // cout<<endl;
    }
    cout<<mx+1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}