#include<bits/stdc++.h>
using namespace std;
const int N=10009;
int ttime[N][N];
int solve[N][N];
int nt,np,ns,nr;
bool cmp1(int a,int b) {
	return a>b;
}
bool cmp(int a,int b) {
	if(solve[a][0]==solve[b][0]) {
		for(int i=1; i<=np; i++)
			if(solve[a][i]!=solve[b][i])
				return solve[a][i]<solve[b][i];
		return a<b;
	}
	return solve[a][0]>solve[b][0];
}
bool cmp2(int a,int b) {
	if(solve[a][0]==solve[b][0]) {
		for(int i=1; i<=np; i++)
			if(solve[a][i]!=solve[b][i])
				return false;
		return true;
	}
	return false;
}
int main() {
	cin>>nt>>np>>ns>>nr;
	int t,p,T,d;
	while(ns--) {
		cin>>t>>p>>T>>d;
		if(T>=300)break;
		if(solve[t][p])continue;
		if(d)solve[t][p]=ttime[t][p]+T;
		else ttime[t][p]+=20;
	}
	for(int i=1; i<=nt; i++) {
		sort(solve[i]+1,solve[i]+np+1,cmp1);
		for(int j=1; j<=np; j++)
			if(solve[i][j]) {
				ttime[i][0]+=solve[i][j];
				solve[i][0]++;
			}
	}
	int tank[N];
	for(int i=1; i<=nt; i++)
		tank[i]=i;
	sort(tank+1,tank+nt+1,cmp);
	int r=0;
	for(int i=1; i<=nt; i++) {
		if(!(i!=1&&cmp2(tank[i],tank[i-1])))r=i;
		if(r>nr)break;
		printf("%-4d%-4d%3d%5d\n",r,tank[i],solve[tank[i]][0],ttime[tank[i]][0]);
	}
	return 0;
}