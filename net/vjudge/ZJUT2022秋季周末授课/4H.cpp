#include<bits/stdc++.h>
#define r(i,a,b) for(int i=a;i<=b;i++)
using namespace std; int n,m,p,q,u,v,tat,tot;
map<int,int>f;
int ff(int x) {return x==f[x]?x:f[x]=ff(f[x]);}
void j(int x,int y) {f[ff(x)]=ff(y);}
bool t(int x,int y) {return ff(x)==ff(y);}
int main() {
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(int i=-1*m;i<=n;i++)f[i]=i;
	for(int i=1;i<=p+q;i++){
		scanf("%d%d",&u,&v);
		j(u,v);
	}
	for(int i=-1*m;i<=-1;i++)
	if(t(f[i],-1)) tat++;
	for(int i=1;i<=n;i++)
	if(t(f[i],1)) tot++;
	printf("%d",min(tat,tot));
}