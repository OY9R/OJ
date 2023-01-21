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
const int g[3][6]={{2,2,-2,-2,0,0},{2,2,2,-3,-3,0},{3,3,3,-3,-3,-3}};
void solve(){
    int n;cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n/4;i++)b[i]=4;
    if(n<4||n==7){
        cout<<-1;
        return;
    }
    if(n%2)b[n/4-1]++;
    if(n==6)b[n/4-1]+=2;
    if(n!=6&&n%4>=2)b[n/4-2]+=2;
    int j=1;
    for(int i=0;i<n/4;i++){
        if(b[i]==4)cout<<j+2<<' '<<j+3<<' '<<j<<' '<<j+1<<' ',j+=4;
        if(b[i]==5)cout<<j+2<<' '<<j+3<<' '<<j+4<<' '<<j<<' '<<j+1<<' ',j+=5;
        if(b[i]==6)cout<<j+3<<' '<<j+4<<' '<<j+5<<' '<<j<<' '<<j+1<<' '<<j+2<<' ',j+=6;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}