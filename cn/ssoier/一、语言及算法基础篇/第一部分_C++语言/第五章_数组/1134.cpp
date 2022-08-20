#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	if(s[0]>='0' && s[0]<='9')
	{
		cout << "no" << endl;
		return 0;
	}
	for(int i=0;i<s.size();i++)
	{
		if(!((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]=='_')))
		{
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;
	return 0;
}