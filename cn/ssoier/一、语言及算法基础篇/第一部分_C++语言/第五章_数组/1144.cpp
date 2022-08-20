#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[505];
	cin.getline(s, 505);
	int b = 0, len = strlen(s);
	for(int i = 0; i <= len; ++i)
	{
		if(s[i] == ' ' || s[i] == '\0')
		{
			for(int j = i - 1; j >= b; j--)
				cout << s[j];
			cout << ' ';
			b = i + 1;
		}
	}
    return 0;
}