#include<bits/stdc++.h>
using namespace std;
const int N=101;
int m[N];
void solve(){
	int n,c;
	cin>>n>>c;
	memset(m,0,sizeof(int)*N);
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		m[t]++;
	}
	int ans=0;
	for(int i=1;i<N;i++){
		if(m[i]>c)ans+=c;
		else ans+=m[i];
	}
	cout<<ans<<endl;
}
int main() {
	int _;
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}