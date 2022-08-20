#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, s_mx;
    while(cin >> s)
    {
    	if(s[s.length()-1] == '.')
    		s.pop_back();
		if(s.length() > s_mx.length())
			s_mx = s;
	}
	cout << s_mx;
    return 0;
}