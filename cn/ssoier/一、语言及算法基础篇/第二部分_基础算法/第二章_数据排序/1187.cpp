#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s[1005];
	int ct[26] = {}, mxi = 0, len;
	cin >> s;
	len = strlen(s);
	for(int i = 0; i < len; ++i) 
		ct[s[i] - 'a']++;
	for(int i = 0; i < 26; ++i)
	{
		if(ct[i] > ct[mxi])
            mxi = i;
	}
	cout << char(mxi+'a') << ' ' << ct[mxi];
	return 0;
}