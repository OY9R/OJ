#include "bits/stdc++.h"
using namespace std;
#define ll long long
int n, x, t;
ll a[200000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--) {
		cin>>n>>x;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int ans=0;
		ll s=a[0],b=a[0];
		for(int i=1;i<n;i++){
			s=min(s,a[i]);
			b=max(b,a[i]);
			if(b-s>2*x){
				ans++;
				s=a[i];
				b=a[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
