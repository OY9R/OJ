#include<bits/stdc++.h>
using namespace std;
const int N=100000100;
int stone[N];
int diff[N];
int L,n,m;
int check(int a){
	// 当最短跳跃距离为a时需要移除的石头数
	int l=0,ret=0;
	for(int i=1;i<=n+1;i++){
		if(stone[i]-stone[l]<a)
			ret++;
		else
			l=i;
	}
	return ret;
}
int main() {
	cin>>L>>n>>m;
	stone[0]=0;
	for(int i=1;i<=n;i++)
		cin>>stone[i];
	stone[n+1]=L;
	int l=0,r=L,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)<=m)l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}