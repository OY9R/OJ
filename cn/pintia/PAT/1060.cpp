#include<iostream>
#include<stdio.h>
using namespace std;
int num[1000005];
int main(){
	int n,mmax=-1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		num[temp]++;
		mmax=max(mmax,temp);
	}
	int cnt=0,ans=-1;
	for(int i=0;i<=mmax;i++){
		cnt+=num[i];
		if(n-cnt>=i)
			ans=max(ans,i);
	}
	printf("%d\n",ans);
	return 0;
}