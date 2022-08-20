#include <bits/stdc++.h>
using namespace std;
int main()
{
	char c;
	while((c = getchar()) != EOF)
	{
		if(islower(c))
			c = (c - 'a' + 1) % 26 + 'a';
		else if(isupper(c))
			c = (c - 'A' + 1) % 26 + 'A';
		cout<<c;
	}
	return 0;
}