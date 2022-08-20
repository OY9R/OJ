#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[55], r[55], c;
	cin>>s;
	int len = strlen(s), r_i = 0;
	for(int i = len - 1; i >= 0; i--)
	{
		c = s[i];
		if(c >= 'a' && c <= 'z')
			c = (c - 'a' + 3) % 26 + 'A';
		else if(c >= 'A' && c <= 'Z')
			c = (c - 'A' + 3) % 26 + 'a';
		r[r_i++] = c; 
	} 
	r[r_i] = '\0';
	cout<<r;
	return 0;
}