#include <iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
double a;
void solve()
{
    for (double a =-4; a < 2; a += 0.1)cout << a << ' ' << int(a) << '\n';//向0靠整
    for (double a = -4; a < 2; a += 0.1)cout << a << ' ' << int(a+0.5) << '\n';//+:四舍五入 -:Nan
}
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 1;//cin>>t;
    while (t--)solve();
}