#include<bits/stdc++.h>
using namespace std;
long long toVal(string s, int b)
{
	long long val = 0;
	for(int i = 0; i < s.length(); ++i)
		val = val * b + s[i] - '0';
	return val;
}
bool check(string s, int b)
{
	for(int i = 0; i < s.length(); ++i)
		if(s[i] - '0' >= b)
			return false;
	return true;
}
int main()
{
	string s_p, s_q, s_r;
	long long p, q, r;
	cin >> s_p >> s_q >> s_r;
	for(int b = 2; b <= 40; ++b)
	{
		if(check(s_p, b) && check(s_q, b) && check(s_r, b))
		{
			p = toVal(s_p, b);
			q = toVal(s_q, b);
			r = toVal(s_r, b);
			if(p * q == r)
			{
				cout << b;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}