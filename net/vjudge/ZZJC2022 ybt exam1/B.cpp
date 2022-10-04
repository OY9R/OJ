#include<bits/stdc++.h>
using namespace std;
int main() {
	unsigned long a,b,c,d,e;
	while(scanf("%lu.%lu.%lu.%lu/%lu\n",&a,&b,&c,&d,&e)==5) {
		unsigned long ip=((a<<24)+(b<<16)+(c<<8)+d);
		ip=e?ip>>(32-e)<<(32-e):0;
		printf("%lu.%lu.%lu.%lu\n",ip>>24,(ip>>16)&0xff,(ip>>8)&0xff,ip&0xff);
	}
	return 0;
}