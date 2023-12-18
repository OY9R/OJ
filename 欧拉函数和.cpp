#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
const int N = 3000005;

int prime[N];
ll phi[N];
int a[N],b[N],tot=1,maxn;

void euler(int n)
{
	int m=0;
	for(int i=2;i<=n;i++)
	{
		if(!phi[i]) prime[++m]=i,phi[i]=(ll)(i-1); //是质数
		for(int j=1;i*prime[j]<=n&&j<=m;j++)
		{
			phi[i*prime[j]]=phi[i]*(ll)(i%prime[j]?prime[j]-1:prime[j]); //不能整除或能整除
			if(i%prime[j]==0) break;
		}
	}
	for(int i=1;i<=n;i++) phi[i]+=phi[i-1];
}

int main()
{
	while(scanf("%d%d",&a[tot],&b[tot])!=EOF) maxn=max(maxn,b[tot]),tot++; //离线处理
	euler(maxn);
	for(int i=1;i<tot;i++) printf("%lld\n",phi[b[i]]-phi[a[i]-1]);
	return 0;
}
