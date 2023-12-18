#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<cmath>
#include<time.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n,s,t,u,v;
vector<int>es[N];
ll ans = 0;
clock_t a;
void solve()
{
	//cin >> n >> s >> t;
	a = clock();
	for (int i = 1; i < 1e8; i++)// ll same 1e8-100ms
	{
		//1e8to10000000(int) 90
		//null 103
		//int b
		//int b=1 108
		//u = 1, v = 1; u += v; 115
		//u= 1456476, v= 1479578; u+=v;115
		//u = 1456476, v = 1479578; u *= v; 115
		//u = 1456476, v = 1479578; u /= v; 180!
		//u = 1456476, v = 1479578; u %= v; 170!
	}
	cout << "TimeA:" << double(clock() - a) << '\n';
	//
	a = clock();//wojfeihi2rnvjorv
	for (int i = 1; i < 100000000; i++)
	{
		u = 1456476, v = 1479578; u %= v;
		//ans += v;
	}
	cout << "TimeA:" << double(clock() - a) << '\n';
	//cout << ans << '\n';
}
int main()
{
	int t = 1; //cin >>t;
	while (t--)solve();
}