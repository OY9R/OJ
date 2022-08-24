#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 1e4;
LL dp[20190325];   //数列从1下标开始
int main() {
	int n;
	while(cin>>n){
		dp[1] = dp[2] = dp[3] = 1;
		
		//添加代码
		//************Begin**************//
		for(int i=4;i<=n;i++){
			dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%10000;
		}
		//************End***************//
		cout << dp[n] << endl;
	}
	return 0;
}
