#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    if(a%2 == 1 && b%2 == 1)
        return a > b;
    else if(a%2 == 0 && b%2 == 0)
        return a < b;
    else
        return a%2 == 1;
}
int main()
{
    int a[15];
	for(int i = 1; i <= 10; ++i)
	    cin >> a[i];
    sort(a+1, a+1+10, cmp);
    for(int i = 1; i <= 10; ++i)
        cout << a[i] << ' '; 
	return 0;
}