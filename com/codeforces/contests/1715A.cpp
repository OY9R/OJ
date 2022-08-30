#include "bits/stdc++.h"
using namespace std;
#define ll long long
int i,j,k,l;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		if(x==1&&y==1)
			cout<<0<<endl;
		else
		    cout<<(x-1+y-1)*2-max(x,y)+2<<endl;
	}
	return 0;
}
