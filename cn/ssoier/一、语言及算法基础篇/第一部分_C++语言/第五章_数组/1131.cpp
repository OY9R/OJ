#include <iostream>
#include <string>
using namespace std;
int main()
{
	double x,sum=0;
	string s1,s2;

	cin >> x >> s1 >> s2;
	for(int i=0;i<s1.size();i++)
		if(s1[i]==s2[i])
			sum++;
	if(sum/s1.size()>=x)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}