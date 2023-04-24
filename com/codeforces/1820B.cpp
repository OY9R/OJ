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
    ll n=s.size();
    s+=s;
    ll maxn=0,num=0;
    for(int i=0;i<n*2;i++){
        if(s[i]=='1')num++;
        else maxn=max(maxn,num),num=0;
    }
    maxn=max(maxn,num);
    // cout<<maxn<<' ';
    if(maxn>=n){
        cout<<n*n<<endl;
        return;
    }else{
        cout<<(maxn+1)/2*((maxn+2)/2)<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}
// 