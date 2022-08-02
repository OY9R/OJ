#include<bits/stdc++.h>
using namespace std;
int main()
{
    double s = 0;
    int n, k;
    cin>>k;
    for(n = 1; s <= k; ++n)
        s += 1.0 / n;
    cout<<n - 1;
    return 0;
}