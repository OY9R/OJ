#include "bits/stdc++.h"
using namespace std;
#define ll long long
int t, n, h, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		cin >> n >> h >> m;
		int ah=24, am=59;
		for (int i = 0; i < n; ++i)
		{
			int hh,mm;
			cin >> hh >> mm;
			hh-=h;
			mm-=m;
			if (mm<0) {
				mm+=60;
				hh-=1;
			}
			if (hh<0) {
				hh+=24;
			}
			if (ah>hh||(ah==hh&&am>mm)) {
				ah=hh;am=mm;
			}
		}
		cout<<ah<<' '<<am<<endl;
	}
	return 0;
}
