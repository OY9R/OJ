#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200010;
typedef long long LL;
int n, m;
int a[N];
int main()
{
	while(cin >> n >> m){
		int k = n + m + 1;
		for(int i = 0; i < k; i ++) scanf("%d", &a[i]);
		LL ans = 0;
		if(!m){
			for (int i = 0; i < n + m + 1; i ++) ans += a[i];
		}else{
			sort(a, a + k);
			ans = a[n + m] - a[0];
			for (int i = 1; i < k - 1; i ++) ans += abs(a[i]);                   
		}
		cout << ans << endl;
	}
	return 0;
}
