#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x, a, b, c;
	cin>>a>>b>>c;
	int ab = abs(a - b), bc = abs(b - c);
	for(int x = 2; x <= 1000000; x++)
    {
        if(ab % x == 0 && bc % x == 0)
        {
            cout<<x;
            break;
        }
    }
	return 0;
}