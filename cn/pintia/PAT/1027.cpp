#include "bits/stdc++.h"
using namespace std;
int getsum(int n)
{
	int sum=0;
	for(int i=1;i<=n;i+=2)
		sum+=i;
	return 2*sum-1;
}
int main()
{
	int n,tar,ans=0;
	char c;
	scanf("%d %c",&n,&c);
	for(int i=1;i<=n;i++)
	{
		if(getsum(2*i-1)>n)
		{
			tar=i-1;
			ans=n-getsum(2*(i-1)-1);
			break;
		}
		else if(getsum(2*i-1)==n)
		{
			tar=i;
			ans=0;
			break;
		}
	}
	int len=2*tar-1;
	for(int i=0;i<2*tar-1;i++)
	{
		if(i<tar)
		{
			for(int j=0;j<i;j++)
				printf(" ");
			for(int j=0;j<2*(tar-i)-1;j++)
				printf("%c",c);
			
			printf("\n");
		}
		else
		{
			for(int j=0;j<(len-(2*(i-tar+1)+1))/2;j++)
				printf(" ");
			for(int j=0;j<2*(i-tar+1)+1;j++)
				printf("%c",c);
			
			printf("\n");	
		}
	}
	printf("%d\n",ans);
	return 0;
} 
