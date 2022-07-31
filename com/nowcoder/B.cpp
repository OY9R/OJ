#include "bits/stdc++.h"
using namespace std;
#define ll unsigned long long
#define MAXN 1000001
int n;
ll k;
ll t[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>k;
	for(int i=0; i<n; i++) {
		cin>>t[i];
	}
	ll maxt = t[0];
	for(int i=1; i<n; i++) {
		maxt = max(maxt,t[i]);
	}
	if(k>maxt) {
		cout<<0<<endl;
	} else {
		cout<<maxt-k<<endl;
	}
	return 0;
}
