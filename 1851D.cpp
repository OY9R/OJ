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
	int n;cin>>n;
    VL a(--n);
    rep(i,0,n)cin>>a[i];
    per(i,1,n)a[i]-=a[i-1];
    // sort(all(a));
    // rep(i,0,n)cout<<a[i]<<' ';
    // cout<<endl;
    vector<bool> vis(n+2,0);
    ll sum=0;
    bool flag=0;
    int j=0;
    rep(i,0,n){
        if(a[i]>n+1||vis[a[i]]){
            if(flag){
                cout<<"No"<<endl;
                return;
            }
            flag=1;
            sum+=a[i];
        }else{
            vis[a[i]]=1;
        }
    }
    rep(i,1,n+2)if(!vis[i]){
        sum-=i;
        j++;
    }
    // cout<<sum<<' '<<j<<endl;
    if((sum==0&&j==2)||(j==1))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}