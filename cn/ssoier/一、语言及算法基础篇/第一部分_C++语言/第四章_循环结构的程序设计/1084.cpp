#include<bits/stdc++.h>
using namespace std;
int solve(int a, int b)
{
    if(b == 1)
        return a;
    else
        return solve(a, b - 1) * a % 1000;
}
int main()
{
	int a, b, s; 
	cin>>a>>b;
	s = solve(a, b);
	if(s < 10)
		cout<<"00";
	else if (s < 100)
		cout<<'0';
	cout<<s;
	return 0;
}