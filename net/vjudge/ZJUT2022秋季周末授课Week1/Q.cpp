#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;
const int N=1e5+9;
int cnt1[30];
int main() {
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		for(int j=0;j<30&&a>0;j++){
			if(a&1)cnt1[j]++;
			a>>=1;
		}
	}
	ll ans=0;
	for(int i=29;i>=0;i--)
		if(cnt1[i]){
			ans=(ans<<1)%MOD;
			ans=(ans+(ll)cnt1[i]*(n-cnt1[i]))%MOD;
		}
	cout<<ans%MOD<<endl;
	return 0;
}