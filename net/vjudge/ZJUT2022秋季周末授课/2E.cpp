#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10001];
int main() {
	int n,k;
	while(cin>>n>>k&&n!=0) {
		for(int i=0; i<n; i++)
			cin>>a[i];
		sort(a,a+n);
		ll ans=0;
		for(int i=1; i<=k; i++)
			ans+=a[n-i];
		cout<<ans<<endl;
	}
	return 0;
}