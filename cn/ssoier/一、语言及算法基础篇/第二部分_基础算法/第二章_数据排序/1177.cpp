#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, a[505], x, an = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> x;
        if(x % 2 == 1)
            a[++an] = x;
    }
    sort(a+1, a+1+an);
    cout << a[1];
    for(int i = 2; i <= an; ++i)
        cout << ',' << a[i];
	return 0;
}