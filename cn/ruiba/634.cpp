#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define maxn 2000
const int mod = 2e9+7;
int n, m, ans;
int dp[maxn][maxn];

int main() {
	while(cin >> n >> m){
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i][j] = 0;
			}
		}
		for(int i=1;i<=m;i++){
			dp[1][i] = 1;
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=j;k<=m;k+=j){
					dp[i][j] += dp[i-1][k];
					dp[i][j] %= mod;
				}
			}
		}
		ans = 0;
		for(int i=1;i<=m;i++){
			ans += dp[n][i];
			ans %= mod;
		}		
		cout << ans << endl;
	}
	return 0;
}
