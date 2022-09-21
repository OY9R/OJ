#include<bits/stdc++.h>
using namespace std;
int main(){
	long long h,m,k;
	scanf("%lld:%lld %lld",&h,&m,&k);
	while(k<0)k+=24*60*1000000;//玄学AC
	k%=24*60;
	long long t=h*60+m+k;
	t%=24*60;
	printf("%02lld:%02lld\n",t/60,t%60);
	return 0;
}