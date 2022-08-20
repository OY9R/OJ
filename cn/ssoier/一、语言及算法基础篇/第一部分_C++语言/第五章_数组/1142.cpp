#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[1005];
	bool isFirst = true;
	while(cin>>s)
	{
		if(isFirst)
			isFirst = false;
		else
			cout<<',';
		cout<<strlen(s);
	}
	return 0;
}