#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> s;
		if(s[0] >= 'a' && s[0] <= 'z')//如果首字母是小写字母
			s[0] = s[0] - 'a' + 'A';//变为大写字母
		for(int j = 1;j < s.length(); ++j)
		{
			if(s[j] >= 'A' && s[j] <= 'Z')//如果某字母是大写字母
				s[j] = s[j] - 'A' + 'a';//变为小写字母
		}
		cout << s << endl;
	}
	return 0;
}