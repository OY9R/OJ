#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debugging 0
#define pii pair<int, int>
const int maxn = 200010;
int n, k, m;
int x, y, z;
int a[maxn];
int b[maxn];
int c[maxn];
void solve() { 
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &b[i]);
    }
    int pre = b[1], k = 1;
    for (int i = 2; i <= m; ++i) { // 去重 保留递减元素 
        if (b[i] < pre) {
            pre = b[i];
            b[++k] = b[i];
        }
    }
    m = k;
    c[m] = 1 << (b[m] - 1);
    for (int i = m - 1; i >= 1; --i) { // 后缀和 
        c[i] = c[i+1] |  (1 << (b[i] - 1));
    }
    if (debugging) {
        printf("c:\n");
        for (int i = 1; i <= m; ++i) {
            printf("%d ", c[i]);
        }
        printf("\n");
    }

    set<pii> vp;
    for (int i = 1; i <= m; ++i) {
        vp.insert({b[i], i});
    }
    for (int i = 1; i <= n; ++i) {
        x = a[i];
        if (!x) { // 0特判 
            printf("%d ", c[1]);
            continue;
        }
        int bit = x & (-x), pos = -1;
        while (bit) {
            bit >>= 1;
            ++pos; // 当前ai的二进制表达下的对应bit为1的最小下标  
        }
        pii p = {pos, m + 1};

        auto it = vp.upper_bound(p); // upper_bound是 > 
        if (it != vp.begin()) { // 找到最后一个 <= pos的下标位置 
            --it;
            x |= c[it->second];
        }


        printf("%d ", x);
    }
    printf("\n");

}
int main(){
	int n;cin>>n;
	while(n--)solve();
	return 0;
}