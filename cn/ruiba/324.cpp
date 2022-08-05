#include <bits/stdc++.h>
using namespace std;
constexpr int N = 19;
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int n, m, sx, sy, ex, ey, cnt;
int w[N][N], st[N][N];
void dfs(int x, int y, vector<pair<int, int> > v)
{
    if (x == ex && y == ey)
    {
        printf("(%d,%d)", sx, sy);
        for (auto it : v) printf("->(%d,%d)", it.first, it.second);
        printf("\n");
        cnt ++ ;
        return ;
    }
    for (int i = 0; i < 4; ++ i){
        int fx = x + dx[i], fy = y + dy[i];
        if (st[fx][fy] || w[fx][fy] == 0) continue;
        st[fx][fy] = 1;
        v.push_back({fx, fy});
        dfs(fx, fy, v);
        v.pop_back();
        st[fx][fy] = 0;
    }
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i )
        for (int j = 1; j <= m; ++ j) cin >> w[i][j];
    cin >> sx >> sy >> ex >> ey;
    st[sx][sy] = 1;
    vector<pair <int, int> > v;
    dfs(sx, sy, v);
    if (!cnt) cout << -1;
    return 0;
}