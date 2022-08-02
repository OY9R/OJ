#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum = 0, d1, d2, d3, d4;
    cin>>n;
    for(int i = 0; i < n; ++i)
    {
        int num;
        cin>>num;
        d1 = num % 10;//个位
        d2 = num / 10 % 10;//十位
        d3 = num / 100 % 10;//百位
        d4 = num / 1000;//千位
        if(d1 - d2 - d3 - d4 > 0)
            sum += 1;
    }
    cout<<sum;
    return 0;
}