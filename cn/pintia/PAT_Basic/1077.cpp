#include "bits/stdc++.h"
#define ll long long
using namespace std;
int main(){
int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int sum=0,t=0;
		int num[105];
		int g1;
		scanf("%d",&g1);
		for(int j=0;j<n-1;j++){
			int temp;
			scanf("%d",&temp);
			if(temp>=0&&temp<=m)
				num[t++]=temp;	
		}
		sort(num,num+t);
		for(int i=1;i<t-1;i++)
			sum+=num[i];
		sum/=(t-2);
		sum=(double)(sum+g1)/2+0.5;
		printf("%d\n",sum);
	}
	return 0;
 } 