#include "bits/stdc++.h"
using namespace std;
long num[100005];
int main()
{
	int N,ans=0;
	long p;
	scanf("%d %ld",&N,&p);
	for(int i=0;i<N;i++)
		scanf("%ld",&num[i]);
	sort(num,num+N);
	for(int i=0;i<N;i++){
		for(int j=i+ans;j<N;j++){
			if(num[j]<=num[i]*p)
				ans=j-i+1;
			else 
				break;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
