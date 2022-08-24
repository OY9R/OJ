#include "bits/stdc++.h"
using namespace std;
int dp[201][10][10],a[201],b[201],c[10],d[20];
int i,j,k,n,m,s,tmp;
int main(){
	while(cin>>n){
		if(!n)break;
		for(i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			for(j=0;j<=8;j++)
				for(k=0;k<=8;k++)
					dp[i][j][k]=0;
		}
		dp[1][1][0]=a[1];
		dp[1][0][1]=b[1];
		for(i=2;i<=n;i++)
			for(j=0;j<=8&&j<=i;j++)
				for(k=0;k<=8&&j+k<=i;k++){
			if(j+k==0)continue;
			tmp=dp[i-1][j][k];
			if(j>0)tmp=max(tmp,dp[i-1][j-1][k]+a[i]);
			if(k>0)tmp=max(tmp,dp[i-1][j][k-1]+b[i]);
			dp[i][j][k]=tmp;
		}
		cout<<dp[n][8][8]<<endl;
		j=k=8;s=0;
		for(m=n;m>=1;m--){
			if(s==16)break;
			if(dp[m][j][k]!=dp[m-1][j][k]){
				s++;
				c[s]=m;
				if(j>0){
					if(dp[m][j][k]==dp[m-1][j-1][k]+a[m]){
						d[s]=1;
						j--;
					}else{
						d[s]=2;
						k--;
					}
				}else{
					d[s]=2;
					k--;
				}
			}
		}
		for(i=16;i>=1;i--)
			cout<<c[i]<<' '<<a[c[i]]<<' '<<b[c[i]]<<' '<<d[i]<<endl;
	}
	return 0;
}
