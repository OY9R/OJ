#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, a; 
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{ 
			cin >> a;
			if(a > 0)
				cout << i << ' ' << j << ' ' << a << endl;
		}
	return 0;	
}