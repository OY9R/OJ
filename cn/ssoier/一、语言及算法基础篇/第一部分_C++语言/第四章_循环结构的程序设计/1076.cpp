#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, h, l, c = 0, cm = 0;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> h >> l;
		if(h >= 90 && h <= 140 && l >= 60 && l <= 90){
			c++;
			if(c > cm)
				cm = c;
		}else
			c = 0;
	}
	cout << cm;
	return 0;
}