#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[105];
    cin.get(s, 105);
	int len = strlen(s);
    for(int i = 0; i < len; ++i)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] + 'A' - 'a';
    }
    cout<<s;
    return 0;
}