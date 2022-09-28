#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500100;
ll x[N],s[N],f[N];
ll q[N],h,t;
ll n,d,k;
bool check(ll g) {
	memset(f,128,sizeof(f));
	f[0]=0; 
	for(int i=0;i<n;++i)
		for(int j=i+1;j<=n;++j){
		if(x[j]-x[i]>d+g) break;
		if(x[j]-x[i]<max(d-g,(ll)1)) continue;
		f[j]=max(f[j],f[i]+s[j]);
		if(f[j]>=k) return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>d>>k;
	for(int i=1; i<=n; i++)
		cin>>x[i]>>s[i];
	ll l=0,r=INT_MAX>>1,ans;
	while(l<=r) {
		ll m=(l+r)>>1;
		if(check(m))ans=m,r=m-1;
		else l=m+1;
	}
	cout<<l<<endl;
	return 0;
}