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
int n;
string s;
void solve(){
    if(!(cin>>s))exit(0);
    n=s.size();
    VL a(n);
    unordered_set<ll> c;
    for(int i=0;i<n;i++)a[i]=s[i]-'0',c.insert(a[i]);
    if(c.size()<10)
        for(int i=0;i<10;i++)
            if(c.count(i)==0){
                cout<<i<<endl;
                return;
            }
    ll o=10;
    for(int k=1;k<n;k++){
        for(int i=n-1;i>=k;i--)a[i]=a[i-1]*10+s[i]-'0',c.insert(a[i]);
        o*=10;
        if(c.size()<o)
            for(ll i=o/10;i<o;i++)
                if(c.count(i)==0){
                    cout<<i<<endl;
                    return;
                }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while(true)solve();
    return 0;
}