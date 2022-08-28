#include "bits/stdc++.h"
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,a,b,c;
	cin>>n>>a>>b>>c;
	if(c>=a||b+c>n){
		cout<<n/a<<endl;
		return 0;
	}
	int ans=0;
	if((n-c)/b*c>=n-b){
		ans=max((n-b)/c,(ll)0);
		ans+=max((n-ans*c)/a,(ll)0);
	}else{
		ans=max((n-c)/b,(ll)0);
		ans+=max((n-ans*c)/a,(ll)0);
	}
	cout<<ans<<endl;
	return 0;
}
