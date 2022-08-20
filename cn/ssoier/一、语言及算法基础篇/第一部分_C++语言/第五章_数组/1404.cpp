#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int y = 1; y <= 100000; ++y)
		for(int x = 1; x <= y; ++x)
			if((1+y)*y/2-3*x == n)
			{
				cout << x << ' ' << y;
				return 0;		
			}
	return 0;
}