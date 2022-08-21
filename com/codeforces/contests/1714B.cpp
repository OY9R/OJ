#include "bits/stdc++.h"
using namespace std;
#define ll long long
int t, n, h, m;
bool nn[200001];
int mm[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> mm[i];
			nn[i]=false;
		}
		bool flag = false;
		for (int i = n; i > 0; i--) {
			if(nn[mm[i]]){
				cout<<i<<endl;
				flag=true;
				break;
			}else{
				nn[mm[i]]=true;
			}
		}
		if(!flag) cout<<0<<endl;
	}
	return 0;
}
