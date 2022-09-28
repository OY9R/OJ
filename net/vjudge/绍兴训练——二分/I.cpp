#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100100;
ll a[N],b[N],k;
int n;
bool check(ll m){
	ll kk=k;
	for(int i=0;i<n;i++){
		if(a[i]*m>b[i])kk-=(a[i]*m-b[i]);
		if(kk<0)return false;
	}
	return true;
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	ll l=0,r=INT_MAX,ans;
	while(l<=r){
		ll mid=l+(r-l)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}//Shaoxing--binary