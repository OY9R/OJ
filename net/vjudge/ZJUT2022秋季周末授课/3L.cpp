#include<bits/stdc++.h>
#define MAXN 3000005
using namespace std;
int n,a[MAXN],Mysta[MAXN],ans[MAXN],top;
inline int read() {
	int x(0);
	char c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c))
		x=(x*10)+(c^48),c=getchar();
	return x;
}
int main() {
	n=read();
	for(int i=1; i<=n; ++i)
		a[i]=read();
	for(int i=1; i<=n; ++i) {
		while(top&&a[Mysta[top]]<a[i])
			ans[Mysta[top]]=i,--top;
		Mysta[++top]=i;
	}
	for(int i=1; i<=n; ++i)
		printf("%d ",ans[i]);
}