#include <iostream>
using namespace std;
int main()
{
	int k,num,c1=0,c2=0,c3=0;
	cin >> k;
	for (int i=1;i<=k;i++)
	{
		cin >> num;
		if(num==1)
		{
			c1++;
		}
		else if(num==5)
		{
			c2++;
		}
		else if(num==10)
		{
			c3++;
		}
	}
	cout << c1 << endl << c2 << endl << c3 << endl;
	return 0;	
}
