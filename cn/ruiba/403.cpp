#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define maxn 100000
int n,m;
ll l[maxn];
int d[maxn];
int p[maxn];

bool cmp1(int lhs,int rhs)//升序
{
	return d[lhs]<d[rhs];
}
bool cmp2(int lhs,int rhs)//升序
{
	return l[lhs]/d[lhs]<l[rhs]/d[lhs];
}

int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>d[i];
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp2);
	sort(p+1,p+n+1-m,cmp1);
	ll emp=0,work=0;
	for(int i=1;i<n;i++){
		emp += (d[p[i]] - d[p[i-1]])*work;
		if(l[p[i]]>emp){
			work+=(l[p[i]]-emp)/d[p[i]] + ((l[p[i]]-emp)%d[p[i]]?1:0);
			emp=(l[p[i]]-emp)%d[p[i]]?d[p[i]]-(l[p[i]]-emp)%d[p[i]]:0;
		}else{
			emp-=l[p[i]];
		}
	}
	cout<<work<<endl;
	return 0;
}
