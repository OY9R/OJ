#include <bits/stdc++.h>
using namespace std;
double solve(double n, double x)
{
    if(n == 0)
        return x;
    else
        return x / (n + solve(n-1, x));
}
int main()
{
    double x, n;
    cin >> x >> n;
    cout << fixed << setprecision(2) << solve(n, x); 
    return 0;
}