#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	int h,m;
	ll k;
	scanf("%d:%d %lld",&h,&m,&k);
	while(k<0)k+=24*60*1000000;
	k%=24*60;
	ll a=h*60+m;
	a+=k;
	a%=24*60;
	printf("%02lld:%02lld\n",a/60,a%60);
	return 0;
}