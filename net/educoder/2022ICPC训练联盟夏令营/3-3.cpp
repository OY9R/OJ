#include "bits/stdc++.h"
using namespace std;
#define ll long long
int dp[10005][10005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s,t;
	cin>>s>>t;
	int ls=s.size();
	int lt=t.size();
	if(s[0]!=t[0])
		dp[0][0]=1;
	for(int i=1;i<lt;i++)
		if(s[i]==t[i])
			dp[i][i]=dp[i-1][i-1];
		else
			dp[i][i]=dp[i-1][i-1]+1;
	for(int i=1;i<ls;i++){
		if(s[i]==t[0])
			dp[i][0]=0;
		else
			dp[i][0]=dp[i-1][0];
	}
	for(int j=1;j<lt;j++)
		for(int i=j+1;i<ls;i++)
			if(s[i]==t[j])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+1);
	cout<<dp[ls-1][lt-1]<<endl;
	return 0;
}
