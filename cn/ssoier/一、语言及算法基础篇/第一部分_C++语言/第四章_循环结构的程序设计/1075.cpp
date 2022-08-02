#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m, n, a, f = 0;
	cin >> m >> n;
	int r = m;
	for(int i = 0; i < n; ++i)
	{
		cin >> a;
		if(r < a)
			f++;
		else
			r -= a;
	} 
	cout << f;
	return 0;
}