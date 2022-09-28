#include<bits/stdc++.h>
using namespace std;
const int N=300100;
int n,k;
int a[N];
bool check(int m){
	for(int i=m;i<=n;i++)
		if(a[i]-a[i-m]<=k)
			return true;
	return false;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i])a[i]=a[i-1];
		else a[i]=a[i-1]+1;
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
	bool flag=true;
	int i;
	for(i=1;i<=n;i++){
		if(a[i+ans-1]-a[i-1]<=k)
			break;
		cout<<1-(a[i]-a[i-1])<<' ';
	}
	for(int i=0;i<ans;i++)
		cout<<"1 ";
	for(i+=ans;i<=n;i++)
		cout<<1-(a[i]-a[i-1])<<' ';
	cout<<endl;
	return 0;
}