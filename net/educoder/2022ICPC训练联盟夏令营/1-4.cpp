#include<stdio.h>
long long m[44];
int main(){
	int t,n,i=4;
	m[2]=1;
	m[3]=2;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(;i<=n;i++){
			m[i]=m[i-2]+m[i-1];
		}
		printf("%lld\n",m[n]);
	}
	return 0;
}
