#include <bits/stdc++.h>
typedef long long ll;
const int MAXN = 1e2 + 10;
int a[MAXN], cnt;
ll sum[MAXN], allAvgs[MAXN * MAXN][2];
int main()
{
    int n; std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
        {
            ll subSum = sum[j] - sum[i - 1];
            ll len = j - i + 1;
            bool flag = 0;
            for (int k = 1; k <= cnt; ++k)
                if (allAvgs[k][0] / allAvgs[k][1] == subSum / len)
                    flag = 1;
            if (!flag)
                allAvgs[++cnt][0] = subSum, allAvgs[cnt][1] = len;
        }
    std::cout << cnt;
    return 0;
}