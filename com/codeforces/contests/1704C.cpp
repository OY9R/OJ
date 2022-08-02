#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n, m, t;
ll a[100000],b[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--) {
		cin>>n>>m;
		for(int i=0;i<m;i++){
			cin>>a[i];
		}
		sort(a,a+m);
		for(int i=1;i<m;i++){
			b[i]=a[i]-a[i-1]-1;
		}
		b[0]=a[0]+n-a[m-1]-1;
		sort(b,b+m,greater<int>());
		int tmp=1;
		ll ans=0;
		for(int i=0;i<m;i++){
			ans+=max((ll)0,b[i]-tmp==0?1:b[i]-tmp);
			tmp+=4;
		}
		cout<<n-ans<<endl;
	}
	return 0;
}
