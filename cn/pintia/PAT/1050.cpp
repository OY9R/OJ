#include"bits/stdc++.h"
using namespace std;
int num[10005];
int ans[10005][1005];
int m,n;
int N;
bool cmp(int a,int b){
	return a>b;
}
void fun(int x,int y,int m,int n,int cnt){
	if(m<=0||n<=0)return;
	for(int i=y;i<y+n;i++)
		ans[x][i]=num[cnt++];
	if(cnt>=N)return;
	for(int i=x+1;i<x+m;i++)
		ans[i][x+n-1]=num[cnt++];
	if(cnt>=N)return;
	for(int i=y+n-2;i>=y;i--)
		ans[x+m-1][i]=num[cnt++];
	if(cnt>=N)return;
	for(int i=x+m-2;i>x;i--)
		ans[i][y]=num[cnt++];
	if(cnt>=N)return;
	fun(x+1,y+1,m-2,n-2,cnt);
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&num[i]);
	for(int i=sqrt(N);i>=1;i--)
		if(N%i==0){
			m=i;
			break;
		}
	n=N/m;
	if(m<n)swap(m,n);
	sort(num,num+N,cmp);
	fun(0,0,m,n,0);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			printf("%d",ans[i][j]);
			if(j==n-1)
				printf("\n");
			else
				printf(" ");
		}
	return 0;
} 