#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long int mmin[100005];
long long int num[100005];
long long int ans[100005];
int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",&num[i]);
	long long int m=num[n-1],mmax=num[0];
	for(int i=n-1;i>=0;i--)
	{
		mmin[i]=min(m,num[i]);
		m=min(m,num[i]);
	}
	for(int i=0;i<n;i++){
		if(num[i]>=mmax&&num[i]<=mmin[i])
		{
			ans[cnt]=num[i];
			cnt++;
		}
		mmax=max(mmax,num[i]);
	}
	sort(ans,ans+cnt);
	printf("%d\n",cnt);
	if(cnt!=0)
		for(int i=0;i<cnt;i++)
		{
			printf("%lld",ans[i]);
			if(i!=cnt-1)
				printf(" ");	
		}
	printf("\n");
	return 0;
}
