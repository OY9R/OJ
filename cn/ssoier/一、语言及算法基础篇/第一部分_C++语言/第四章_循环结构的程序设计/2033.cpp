#include<bits/stdc++.h>
using namespace	std;
#define M 1000000
int main(){
	int n,s=1,v=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		s*=i;
		v+=s;
	}
	printf("%d",v);
	return 0;
}