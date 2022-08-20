#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;
int n, a[N];
int cnt, res[N];
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++){
        if (i == 1 || a[i] != a[i - 1]){
            res[++cnt] = a[i];
        }
    }
    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++){
        cout << res[i] << " ";
    }
    return 0;
}