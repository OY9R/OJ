#include <bits/stdc++.h>
typedef long long ll;
const int MAXN = 2e3 + 10;
int a[MAXN];
int main()
{
    int n; std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    int ans;
    for (int i = 1; i <= n; ++i)
        ans += a[i];
    std::cout << ans;
    return 0;
}