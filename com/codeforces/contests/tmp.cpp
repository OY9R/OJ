#include "bits/stdc++.h"
using namespace std;
#define ll long long
int t, n, k, b, bd;
int m[100000],is[10000],bs[10000];
bool f[100000];
bool dfs(int d,int sum){
	if(sum>k)return false;
	if(sum==k||sum>b){
		b=sum;
		for(int i=1;i<d;i++)
			bs[i]=is[i];
		bd=d;
	}
	for(is[d]=is[d-1]+1;is[d]<=n;is[d]++)
		if(f[is[d]]&&dfs(d+1,sum+m[is[d]]))
			return true;
	return false;
}
// 6/9
int main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>m[i];
		f[i]=true;
	}
	cin>>t;
	for(int i=1;i<=t;i++){
		int j=0,tmp[1000];
		char ch;
		do{
			cin>>tmp[j++];
			ch=getchar();
		}while(ch==' ');
		while(--j){
			m[tmp[0]]+=m[tmp[j]];
			f[tmp[j]]=false;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(f[i]){
			ans++;
			is[0]=i;
			b=m[i];
			dfs(1,m[i]);
			for(int i=1;i<bd;i++)
				f[bs[i]]=false;
		}
	cout<<ans;
	return 0;
}
