#include <bits/stdc++.h>
using namespace std;
int main()
{
	int ct[105] = {}, n, a;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a;
		ct[a+50]++;
	}
	for(int i = -50; i <= 50; ++i)
	{
		if(ct[i+50] > n/2)
		{
			cout << i;
			return 0;
		}
	}
	cout << "no";
	return 0;
}