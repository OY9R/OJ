#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
long long s[10005];
int zs[10005]= {0};
int t=2,tot,ans=0x7fffffff;
int main() {
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i = 1; i <= n ; i ++)
		scanf("%lld",&s[i]);
	if(m1==1) {printf("0"); exit(0); }
	while(m1!=1) {
		while(!(m1%t)) m1/=t,zs[t]++;
		tot=max(tot,t);
		zs[t++]*=m2;
	}
	for(int i = 1; i <= n; i++) {
		int l=0;
		for(int j=2; j<=tot; j++) {
			if(!(zs[j])) continue;
			int sum=0;
			while(!(s[i]%j)) s[i]/=j,sum++;
			if(!sum) {l=0x7fffffff; break;}
			l=max(l,(zs[j]-1)/sum);
		}
		ans=min(ans,l);
	}
	ans=(ans==0x7fffffff?-1:ans+1);
	printf("%d",ans);
}