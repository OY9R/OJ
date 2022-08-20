#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, a[25][25] = {};
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= i; ++j)
		{
			if(j == 1)
				a[i][j] = 1;
			else
				a[i][j] = a[i-1][j] + a[i-1][j-1];
		}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= i; ++j)
			cout << a[i][j] << ' ';
		cout << endl; 
	}
	return 0;	
}