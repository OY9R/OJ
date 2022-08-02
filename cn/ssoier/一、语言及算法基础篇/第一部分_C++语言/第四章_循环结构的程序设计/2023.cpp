#include<bits/stdc++.h> 
using namespace std;
int main()
{
    int a, sum = 0, n = 0, mx = 0, mn = 1001;
    {
    	if(a > mx)
    		mx = a;
    	if(a < mn)
    		mn = a;
    	sum += a;
    	n++; 
	}
	cout << mn << ' ' << mx << ' ';
	cout << fixed << setprecision(3) << (double)sum/n;
	return 0;
}