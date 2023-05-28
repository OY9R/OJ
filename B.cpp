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
    int n,m,M;cin>>n>>m>>M;
    int win=0,ft=0;
    int flag=0;
    while(n&&m&&n+m!=M){
        if(flag)flag++;
        if(n>=m)n-=m,win=0,ft++,flag++;
        else m-=n,win=1;
    }
    if(n+m==M&&(win||ft>1||ft==1&&flag!=1))cout<<"type-c"<<endl;
    else if(n+m==M)cout<<"lovely"<<endl;
    else if(n*m==0)cout<<"draw"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    while(n--)solve();
    return 0;
}