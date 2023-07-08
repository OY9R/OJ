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
	string s1,s2;cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    if(n<m){
        s1=string(m-n,'0')+s1;
        n=m;
    }
    if(n>m){
        s2=string(n-m,'0')+s2;
        m=n;
    }
    ll ans=0,maxans=0;
    rep(i,0,n){
        if(s1[i]!=s2[i]){
            ans+=abs(s1[i]-s2[i]);
            maxans=max(maxans,ans+9*(n-i-1));
        }
    }
    cout<<maxans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	while(n--)solve();
	return 0;
}