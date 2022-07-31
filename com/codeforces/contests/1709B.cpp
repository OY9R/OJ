#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int MAXN = 100001;
int w, t, k, m, h, l, r;
ll world[MAXN],up[MAXN],down[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> w >> t;
	for(int i=1;i<=w;i++){
		cin >> world[i];
		up[i]+=up[i-1]+max((ll)0,world[i]-world[i-1]);
		down[i]=down[i-1]+max((ll)0,world[i-1]-world[i]);
	}
	while (t--) {
		cin >> l >> r;
		ll ans=0;
		if(l > r){
			ans=up[l]-up[r];
		}else{
			ans=down[r]-down[l];
		}
		cout << ans << "\n";
	}
	return 0;
}
