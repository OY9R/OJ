#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int vi[N],wi[N];
int dp[N][N];
int main() {
	int n,v;
	cin>>n>>v;
	for(int i=1; i<=n; i++)
		cin>>wi[i]>>vi[i];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=v; j++)
			if(j<wi[i]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-wi[i]]+vi[i]);
	cout<<dp[n][v];
	return 0;
}