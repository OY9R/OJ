#include<bits/stdc++.h>
using namespace std;
int rmb[]= {100,50,10,5,2,1};
int main() {
	int t;
	while(cin>>t&&t!=0) {
		int ans=0;
		while(t--) {
			int n;
			cin>>n;
			for(int i=0; i<6; i++) {
				ans+=n/rmb[i];
				n%=rmb[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}