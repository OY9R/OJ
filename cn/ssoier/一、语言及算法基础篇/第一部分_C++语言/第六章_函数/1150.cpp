#include<bits/stdc++.h>
using namespace std;

int sumOfFactor(int n)
{
	int s = 0;
	for(int i = 1; i < n; ++i)
		if(n % i == 0)s += i;
	return s;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 2; i <= n; ++i)
		if(sumOfFactor(i) == i)
			cout << i << endl;
	return 0;
}