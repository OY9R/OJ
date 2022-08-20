#include <bits/stdc++.h>
using namespace std;
int main()
{
	char c;
	while((c=getchar())!='\n')
	{
		if(c == 'A')
			cout<<'T';
		else if(c == 'T')
			cout<<'A';
		else if(c == 'G')
			cout<<'C';
		else
			cout<<'G';
	}
	return 0;
}