#include <bits/stdc++.h>
typedef long long ll;
const int MAXN = 2e3 + 10;
int a[MAXN];
int main()
{
    int t; std::cin >> t;
    while (t--)
    {
        int n, s; std::cin >> n >> s;
        int pre = 0; bool flag = 0;
        for (int i = 1; i <= n; ++i)    
        {
            std::cin >> a[i];
            pre += a[i];
            if (pre == s)
            {
                std::cout << "Yes" << std::endl;
                flag = 1;
                break;
            }
        }
        if (!flag) std::cout << "No" << std::endl;
    }
    return 0;
}