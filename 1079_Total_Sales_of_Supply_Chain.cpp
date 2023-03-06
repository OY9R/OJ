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
typedef double db;
const int INF=0x3f3f3f3f,mod=1e9+7;
VI g;int n;db p,r;
vector<double> c;
double dfs(int n){
	if(!c[n])c[n]=dfs(g[n])*(r/100+1);
	return c[n];
}
void solve(){
	cin>>n>>p>>r;
	VI q(n);g.resize(n);c.resize(n);
	for(int i=0;i<n;i++){
		int t,j;cin>>t;
		if(t==0)cin>>q[i];
		while(t--)cin>>j,g[j]=i;
	}
	double sum=0;
	c[0]=p;
	for(int i=0;i<n;i++)
		if(q[i])
			sum+=q[i]*dfs(i);
	printf("%.1lf",sum);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}