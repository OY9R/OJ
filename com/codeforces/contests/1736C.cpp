#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,tmp;
	long long ans=1;
	cin>>n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	b[0]=1;
	for(int i=1;i<n;i++){
		if(a[i]>=b[i-1]+1){
			b[i]=b[i-1]+1;
		}else{
			b[i]=a[i];
		}
		ans+=b[i];
	}
	cout<<ans<<endl;
}
int main(){
	int _;
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}