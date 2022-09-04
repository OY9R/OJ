#include "bits/stdc++.h"
using namespace std;
int num[100005];
int main(){
	for(int i=2;i<100005;i++)
		for(int j=2;i*j<100005;j++)
			num[i*j]=1;
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=4;i<=n;i++)
		if(num[i]==0&&num[i-2]==0)
			cnt++;
	printf("%d\n",cnt);
	return 0;
} 
