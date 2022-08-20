#include<iostream>
using namespace std;
int main()
{
	char c1,c2;
	string s;
	getline(cin,s);
	cin >> c1 >> c2;
	
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==c1)
			cout << c2;
		else
			cout << s[i];
	}
	cout << endl;
	return 0;
}