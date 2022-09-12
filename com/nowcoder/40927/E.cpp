#include<bits/stdc++.h>
using namespace std;
int main() {
	int p,q,n,m;
	cin>>p>>q>>n>>m;
	int c=0;
	for(int i=1; i<n-1; i++)
		c+=i;
	for(int i=n; i<=m; i++) {
		c+=i-1;
		if(c%q==0) {
			int tmp=p*(c/q);
			for(int j=1; j<=i/2; j++) {
				if(j*(i-j)==tmp) {
					cout<<j<<' '<<(i-j)<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"NO SOLUTION"<<endl;
	return 0;
}