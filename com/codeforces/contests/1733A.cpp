#include<bits/stdc++.h>
#define ll long long
using namespace std;
int m[101];
int main() {
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		memset(m,0,sizeof m);
		for(int i=0;i<n;i++){
			int in;
			cin>>in;
			m[i%k]=max(m[i%k],in);
		}
		ll ans=0;
		for(int i=0;i<k;i++){
			ans+=m[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}