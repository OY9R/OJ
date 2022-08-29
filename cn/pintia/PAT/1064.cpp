#include "bits/stdc++.h"
#define ll long long
using namespace std;
int m[10005];
set<int> s;
int main(){
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int t,a=0;
		scanf("%d",&t);
		while(t!=0){
			a+=t%10;
			t/=10;
		}
		m[cnt++]=a;
		s.insert(a);
	}
	sort(m,m+cnt);
	printf("%d\n",s.size());
	printf("%d",m[0]);
	for(int i=1;i<n;i++){
		if(m[i]==m[i-1])
			continue;
		printf(" %d",m[i]);
	}
	return 0;
} 