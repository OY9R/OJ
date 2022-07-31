#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define MAXN 3001
#define MAXM 20001
int n,m,x,y,a,b,v;
int t[MAXN],w[MAXN],s[MAXN];
int dp[MAXN][MAXM];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>v;
	for(int i=1; i<=n; i++) {
		cin>>t[i]>>w[i]>>s[i];
	}
	for(int i=1; i<=n; i++)
		for(int j=0; j<=v; j++)
			for(int k=0; k*t[i]<=j && k<=s[i]; k++)
				dp[i][j]=max(dp[i][j],dp[i-1][j-k*t[i]]+k*w[i]);
	cout<<dp[n][v]<<endl;
	return 0;
}
