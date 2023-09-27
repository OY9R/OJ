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
	VL a(n);
    rep(i,0,n)cin>>a[i];
    if(a[0]==a[n-1]){
        ans=0;
        rep(i,0,n)if(a[i]==a[0])ans++;
        if(ans>=m)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }else{
        int l=-1,r=n;
        for(int i=0;l<n-1&&i<m;)
            if(a[0]==a[++l])i++;
        for(int i=0;r>0&&i<m;)
            if(a[n-1]==a[--r])i++;
        // cout<<l<<' '<<r<<' ';
        if(l<r)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}