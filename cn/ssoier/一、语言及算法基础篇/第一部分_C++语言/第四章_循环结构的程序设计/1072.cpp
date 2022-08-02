#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, t, e;
	cin>>n;
	cin>>t>>e;
	double x = (double)e / t, y;
	for(int i = 1; i < n; ++i)
	{
		cin>>t>>e;
		y = (double)e / t;
		if(y - x > 0.05)
			cout<<"better"<<endl;
		else if(x - y > 0.05)
			cout<<"worse"<<endl;
		else
			cout<<"same"<<endl;
	}
	return 0;
}