#include <bits/stdc++.h>
using namespace std;
int main()
{
    double x, n, s = 1;
    cin>>x>>n;
    for(int i = 1; i <= n; ++i)
        s += pow(x, i);
    cout<<fixed<<setprecision(2)<<s;
    return 0;
}