#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int main(){
    long long t=read();
    while(t--){
        long long n=read();
        if(n<=1)printf("%lld\n",n);
        else printf("%lld\n",n%2+2);
    }
}