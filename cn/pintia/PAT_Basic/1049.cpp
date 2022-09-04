#include "bits/stdc++.h"
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;i++){
		double t;
		cin>>t;
		ans+=(ll)(10000*t)*i*(n+1-i);
	}
	printf("%.2lf\n",1.0*ans/10000);
	return 0;
}
