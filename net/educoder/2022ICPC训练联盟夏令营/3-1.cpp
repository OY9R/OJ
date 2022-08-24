#include "bits/stdc++.h"
using namespace std;
int exactly[100110][12];
int dp[100110][12];
int n,i,j,row,col,maxx,mmax;
int main(){
	while(cin>>n){
		memset(exactly,0,sizeof(exactly));
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++){
			cin>>row>>col;
			exactly[col][row]++;
			if(col>maxx)maxx=col;
		}
		for(i=0;i<=10;i++)
			dp[maxx][i]=exactly[maxx][i];
		for(i=maxx-1;i>=0;i--){
			for(j=0;j<=10;j++){
				mmax=0;
				if(j-1>=0)
					mmax=dp[i+1][j-1];
				if(dp[i+1][j]>mmax)
					mmax=dp[i+1][j];
				if(dp[i+1][j+1]>mmax&&j+1<=10)
					mmax=dp[i+1][j+1];
				dp[i][j]=exactly[i][j]+mmax;
			}
		}
		cout<<dp[0][5]<<endl;
	}
}
