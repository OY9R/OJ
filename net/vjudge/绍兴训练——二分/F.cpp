#include<bits/stdc++.h>
using namespace std;
const int N=300100;
int n,k;
int a[N];
bool check(int m){
	for(int i=m;i<=n;i++)
		if(a[i]-a[i-m]<=k||m+a[i-m]-a[i]<=k)
			return true;
	return false;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c=='a')a[i]=a[i-1]+1;
		else a[i]=a[i-1];
	}
	int l=0,r=n,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}