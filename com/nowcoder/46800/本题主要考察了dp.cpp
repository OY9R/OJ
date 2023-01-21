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
    int n,m,ans=0;cin>>n>>m;
    if((n+2)/3>=m)cout<<0<<endl;
    else{
        VI a(n);
        ll cnt=0;
        for(int i=0;i<n;i++){
            if(i%3==0)a[i]=1,m--;
        }
        reverse(all(a));
        for(int i=0;m>0;i++){
            if(!a[i])a[i]=1,m--;
        }
        for(int i=0;i<n-2;i++){
            if(a[i]+a[i+1]+a[i+2]>1)cnt++;
        }
        cout<<cnt<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}