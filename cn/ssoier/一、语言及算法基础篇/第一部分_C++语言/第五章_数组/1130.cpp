#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	bool flag=false;
	int letters[26]={0};
	
	cin >> s;
	for(int i=0;s[i]!='\0';i++)
		letters[s[i]-'a']++;
	
	for(int i=0;i<s.size();i++)
	{
		if(letters[s[i]-'a']==1)
		{
			cout << s[i] << endl;
			flag=true;
			break;
		}
	}
	if(flag==false)
		cout << "no" << endl;
    return 0;
}