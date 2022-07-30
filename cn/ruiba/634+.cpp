#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define maxn 200000
const int mod = 2e9+7;
int n, m, ans;
int dp[3][maxn];

int main() {
	while(cin >> n >> m){
		for(int i=2;i<=3;i++){
			for(int j=1;j<=m;j++){
				dp[i%2][j] = 0;
			}
		}
		for(int i=1;i<=m;i++){
			dp[1][i] = 1;
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i%2][j] = 0;
			}
			for(int j=1;j<=m;j++){
				for(int k=j;k<=m;k+=j){
					dp[i%2][j] += dp[(i-1)%2][k];
					dp[i%2][j] %= mod;
				}
			}
		}
		ans = 0;
		for(int i=1;i<=m;i++){
			ans += dp[n%2][i];
			ans %= mod;
		}		
		cout << ans << endl;
	}
	return 0;
}
