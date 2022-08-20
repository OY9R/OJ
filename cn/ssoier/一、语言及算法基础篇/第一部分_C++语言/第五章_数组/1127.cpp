#include<bits/stdc++.h>
using namespace std;
#define N 105
int main(){
    int n, m, a[N][N], b[N][N];
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for(int j = 1; j <= m; ++j){
        for(int i = n; i >= 1; --i)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}