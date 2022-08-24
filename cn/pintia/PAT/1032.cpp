#include "bits/stdc++.h"
#define ll long long
using namespace std;
ll s[100003];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		long b;
		cin>>a>>b;
		s[a]+=b;
		m=max(m,a);
	}
	ll max=0;
	int maxi=0;
	for(int i=1;i<=m;i++){
		if(max<=s[i]){
			max=s[i];
			maxi=i;
		}
	}
	cout<<maxi<<' '<<max<<endl;
	return 0;
}
