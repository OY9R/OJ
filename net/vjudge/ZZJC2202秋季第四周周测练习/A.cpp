#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244352;
ll fastpower(ll m,ll k){
	ll res=1%mod,t=m;
	while(k){
		if(k&1)res=res*t%mod;
		t=t*t%mod;
		k>>=1;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll x,n;
	cin>>x>>n;
	while(n--){
		ll a;
		cin>>a;
		cout<<fastpower(x,a)<<' ';
	}
	return 0;
}