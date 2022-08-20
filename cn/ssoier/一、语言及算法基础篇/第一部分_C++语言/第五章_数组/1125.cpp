#include<bits/stdc++.h>
using namespace std;
#define N 105
int main()
{
    int m, n, k, a[N][N], b[N][N], r[N][N] = {};
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= k; ++j)
            cin >> b[i][j];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= k; ++j)
        	for(int x = 1; x <= m; ++x)
        		r[i][j] += a[i][x] * b[x][j];
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= k; ++j)
            cout << r[i][j] << ' ';
        cout << endl;
    }
    return 0;
}