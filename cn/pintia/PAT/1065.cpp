#include "bits/stdc++.h"
#define ll long long
#define N 100005
using namespace std;
int mm[N],a[N],fs[N],t[N];
int main(){
	memset(mm,-1,sizeof(int));
	int n,m,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		mm[x]=y;
		mm[y]=x;
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>t[i];
		fs[t[i]]=1;
	}	
	for(int i=0;i<m;i++)
		if(fs[mm[t[i]]]==0||mm[t[i]]==-1)
			a[cnt++]=t[i];
	sort(a,a+cnt);
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++){
		printf("%05d",a[i]);
		if(i==cnt-1)
			cout<<endl;
		else
			cout<<' ';
	}
	return 0;
} 