#include "bits/stdc++.h"
using namespace std;
#define ll long long
int x, y, a, b, t;
int n[51], m[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&a,&b);
		for(int i=1; i<=a; i++) {
			scanf("%1d",n+i);
		}
		for(int i=1; i<=b; i++) {
			scanf("%1d",m+i);
		}
		bool flag = true;
		for(int i=0; i<b-1; i++) {
			if(n[a-i]!=m[b-i]) {
				cout << "NO" << endl;
				flag = false;
				break;
			}
		}
		if(flag){
			for(int i=b-1; i<a; i++) {
				if(n[a-i]==m[1]) {
					cout << "YES" << endl;
					flag = false;
					break;
				}
			}
		}
		if(flag){
			cout << "NO" << endl;
		}
	}
	return 0;
}
