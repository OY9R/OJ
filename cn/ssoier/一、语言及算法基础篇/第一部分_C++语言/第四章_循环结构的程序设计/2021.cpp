#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m, n, s;
	cin >> m >> n;
	s = m > n ? n : m;
	for(int i = s; i >= 1; --i)
	{
		if(m % i == 0 && n % i == 0)
		{
			cout << i;
			return 0;
		} 
	}
	return 0;
}