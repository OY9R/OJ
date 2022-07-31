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
		for(int i=0;i<n;i++){
			a[i]=0;
			for(int j=1;j<=m;j++){
				ll tmp;
				cin>>tmp;
				a[i]+=tmp*j;
			}
			cout<<a[i]<<' '<<endl;
		}
		//TODO
		
	}
	return 0;
}
