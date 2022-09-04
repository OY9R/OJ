#include"bits/stdc++.h"
using namespace std;
int main(){
	int n,cnt1=0,cnt2=0;
	scanf("%d",&n);
	while(n--){
		int a1,a2,b1,b2;
		scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
		if(a1+b1==a2&&a1+b1!=b2)
			cnt2++;
		if(a1+b1==b2&&a1+b1!=a2)
			cnt1++;
	}
	printf("%d %d\n",cnt1,cnt2);
	return 0;
} 