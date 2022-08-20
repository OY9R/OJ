#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, s = 0, a[105][105], b[105][105];
    scanf("%d %d", &m, &n);
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> b[i][j];
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
        {
            if(a[i][j] == b[i][j])
                s++;
        }
    printf("%.2f", (double)s/(m*n)*100);
    return 0;
}